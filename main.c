
#include "./libft.h"
#include <stdio.h>




#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>
#include <limits.h>


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "./libft.h"

#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **ft_split(char const *s, char c);

/*
** Malloc-failure tests (the classic ft_split check: if allocation number N
** fails, everything allocated before it must be freed and NULL returned).
**
**   cc -g -DTEST_MALLOC_FAIL -Wl,--wrap=malloc -Wl,--wrap=calloc \
**      -Wl,--wrap=free -fsanitize=address,undefined \
**      test_split.c ft_split.c <your helpers>.c && ./a.out
**
** Inside the "window" (the call to ft_split) the wrappers count allocations,
** fail the Nth one, and count live blocks so a leak is reported immediately.
*/
extern void *__real_malloc(size_t n);
extern void *__real_calloc(size_t a, size_t b);
extern void __real_free(void *p);
static int g_window = 0;
static int g_count = 0;
static int g_fail_at = 0;
static int g_live = 0;

static int should_fail(void)
{
    if (!g_window)
        return 0;
    g_count++;
    return g_count == g_fail_at;
}

void *__wrap_malloc(size_t n)
{
    void *p;

    if (should_fail())
        return NULL;
    p = __real_malloc(n);
    if (p && g_window)
        g_live++;
    return p;
}

void *__wrap_calloc(size_t a, size_t b)
{
    void *p;

    if (should_fail())
        return NULL;
    p = __real_calloc(a, b);
    if (p && g_window)
        g_live++;
    return p;
}

void __wrap_free(void *p)
{
    if (p && g_window)
        g_live--;
    __real_free(p);
}

static int total = 0;
static int fails = 0;

static void fail(const char *name, const char *why)
{
    fails++;
    printf("FAIL  %-44s %s\n", name, why);
    fflush(stdout);   /* the line must appear even if a crash follows */
}

/*
** Expected results are written as words separated by '|':
**   "a|b|c"  -> {"a","b","c",NULL}
**   ""       -> {NULL}   (zero words)
** so '|' must never be a delimiter or part of a word in the tests.
*/
static size_t parse_expected(const char *expected, char *buf, char **words)
{
    size_t n = 0;

    strcpy(buf, expected);
    if (!*buf)
        return 0;
    words[n++] = buf;
    for (char *p = buf; *p; p++)
        if (*p == '|')
        {
            *p = '\0';
            words[n++] = p + 1;
        }
    return n;
}

/* Independent reference splitter: builds the "a|b|c" form of the answer. */
static void ref_expected(const char *s, char c, char *out)
{
    size_t o = 0;
    int in_word = 0;

    for (; *s; s++)
    {
        if (*s == c)
            in_word = 0;
        else
        {
            if (!in_word && o > 0)
                out[o++] = '|';
            out[o++] = *s;
            in_word = 1;
        }
    }
    out[o] = '\0';
}

static void free_words(char **res, size_t n)
{
    for (size_t i = 0; i < n; i++)
        free(res[i]);
    free(res);
}

/* Runs one case. s is copied into an exact-size heap buffer so ASan flags any
   read past its NUL. */
static void check(const char *name, const char *s, char c, const char *expected)
{
    size_t ls = strlen(s);
    size_t le = strlen(expected);
    char *in = malloc(ls + 1);
    char *ebuf = malloc(le + 1);
    char **ewords = malloc((le + 2) * sizeof(char *));
    size_t en = parse_expected(expected, ebuf, ewords);
    char **res;
    size_t n = 0;
    int ok = 1;
    int inside = 0;

    memcpy(in, s, ls + 1);
    res = ft_split(in, c);
    total++;
    if (!res)
    {
        fail(name, "returned NULL (expected an array)");
        goto done;
    }
    /* count entries up to the NULL terminator (stop early if it is missing) */
    while (n < en + 2 && res[n])
        n++;
    if (n != en)
    {
        char msg[120];

        if (n >= en + 2)
            snprintf(msg, sizeof msg, "expected %zu words, array is longer "
                     "or not NULL-terminated", en);
        else
            snprintf(msg, sizeof msg, "expected %zu words, got %zu", en, n);
        fail(name, msg);
        if (n < en + 2)
            free_words(res, n);
        goto done;
    }
    for (size_t i = 0; i < n; i++)
    {
        if (res[i] >= in && res[i] <= in + ls)
        {
            fail(name, "a word points inside s (no copy made)");
            inside = 1;
            ok = 0;
            break;
        }
        if (strcmp(res[i], ewords[i]) != 0)
        {
            char msg[200];

            snprintf(msg, sizeof msg, "word %zu: expected \"%.40s\", got "
                     "\"%.40s\"", i, ewords[i], res[i]);
            fail(name, msg);
            ok = 0;
            break;
        }
    }
    if (ok && n <= 100)
        for (size_t i = 0; i < n && ok; i++)
            for (size_t j = i + 1; j < n; j++)
                if (res[i] == res[j])
                {
                    fail(name, "two words share the same memory");
                    ok = 0;
                    break;
                }
    if (inside)
    {
        free(res);   /* the words belong to s: freeing them would be invalid */
        goto done;
    }
    free(in);        /* words must survive s being freed */
    in = NULL;
    if (ok)
        for (size_t i = 0; i < n; i++)   /* each word block holds len + 1 */
            memset(res[i], 'x', strlen(ewords[i]) + 1);
    free_words(res, n);
done:
    free(in);
    free(ebuf);
    free(ewords);
}

/* Fails allocation 1, then 2, then 3 ... inside ft_split. Every failing run
   must return NULL and leave no live block behind; the first run that does
   not fail must give the correct answer. */
static void check_failures(const char *name, const char *s, char c,
                           const char *expected)
{
    size_t le = strlen(expected);
    char *ebuf = malloc(le + 1);
    char **ewords = malloc((le + 2) * sizeof(char *));
    size_t en = parse_expected(expected, ebuf, ewords);
    char msg[160];
    int done = 0;

    total++;
    for (int n = 1; n <= 500 && !done; n++)
    {
        char **res;

        g_window = 1;
        g_count = 0;
        g_fail_at = n;
        g_live = 0;
        res = ft_split(s, c);
        g_window = 0;
        if (!res)
        {
            if (g_live != 0)
            {
                snprintf(msg, sizeof msg, "malloc #%d failed: %d block(s) "
                         "leaked, not freed", n, g_live);
                fail(name, msg);
                done = 1;
            }
            continue;
        }
        /* allocation n was never reached: this is the normal result */
        size_t k = 0;

        while (k < en + 2 && res[k])
            k++;
        if (k != en)
            fail(name, "wrong result once nothing fails");
        else
            for (size_t i = 0; i < k; i++)
                if (strcmp(res[i], ewords[i]) != 0)
                {
                    fail(name, "wrong word once nothing fails");
                    break;
                }
        if (k < en + 2)
            free_words(res, k);
        done = 1;
    }
    if (!done)
        fail(name, "still failing after 500 allocation failures");
    free(ebuf);
    free(ewords);
}

int main(int argc, char **argv)
{
    /* --- basic splitting --- */
    check("two words", "hello world", ' ', "hello|world");
    check("five words", "a b c d e", ' ', "a|b|c|d|e");
    check("words of different length", "a bb ccc dddd eeeee", ' ',
          "a|bb|ccc|dddd|eeeee");
    check("single-character words", "a b c", ' ', "a|b|c");
    check("two words, two letters", "ab cd", ' ', "ab|cd");

    /* --- no delimiter in the string: one word, still a copy --- */
    check("no delimiter present", "one", ' ', "one");
    check("single character", "x", ' ', "x");
    check("delimiter absent, other chars", "hello", ',', "hello");

    /* --- repeated, leading and trailing delimiters --- */
    check("multiple, leading, trailing", "  hello  world  ", ' ', "hello|world");
    check("leading only", "   hello", ' ', "hello");
    check("trailing only", "hello   ", ' ', "hello");
    check("consecutive in the middle", "a,,b,,,c", ',', "a|b|c");
    check("single leading", ",a", ',', "a");
    check("single trailing", "a,", ',', "a");
    check("both ends, one word", ",a,", ',', "a");
    check("many at both ends", "xxaxxbxx", 'x', "a|b");

    // /* --- nothing but delimiters, or nothing at all: {NULL}, never NULL --- */
    check("empty string", "", ',', "");
    check("empty string, space delimiter", "", ' ', "");
    check("single delimiter", ",", ',', "");
    check("only delimiters", ",,,,", ',', "");
    check("single space", " ", ' ', "");
    check("only spaces", "      ", ' ', "");
    check("all chars are the delimiter", "aaa", 'a', "");
    check("one char, equal to delimiter", "a", 'a', "");

    /* --- delimiter at one position of a word --- */
    check("delimiter first char", "abc", 'a', "bc");
    check("delimiter last char", "abc", 'c', "ab");
    check("delimiter in the middle", "abc", 'b', "a|c");

    /* --- different delimiter characters --- */
    check("newline delimiter", "line1\nline2\n\nline3", '\n', "line1|line2|line3");
    check("tab delimiter", "a\tb\t\tc", '\t', "a|b|c");
    check("digit delimiter", "a1b2c3", '1', "a|b2c3");
    check("punctuation delimiter", "a.b.c", '.', "a|b|c");
    check("case sensitive, lower", "aAbB", 'a', "AbB");
    check("case sensitive, upper", "aAbB", 'A', "a|bB");
    check("high-bit delimiter 0xFF", "x\xffy\xffz", '\xff', "x|y|z");
    check("high-bit delimiter 0xE9", "x\xe9y", '\xe9', "x|y");

    /* --- other whitespace is NOT a delimiter unless asked for --- */
    check("spaces kept inside words", "hello world,foo bar", ',',
          "hello world|foo bar");
    check("tab kept when delimiter is space", "a\tb c", ' ', "a\tb|c");
    check("punctuation inside words", "!@# $%^", ' ', "!@#|$%^");

    /* --- delimiter '\0': nothing inside the string equals it, so the whole
           string is one word (or no word if it is empty) --- */
    check("delimiter is NUL, non-empty", "hello", '\0', "hello");
    check("delimiter is NUL, empty", "", '\0', "");

    /* --- NUL inside the buffer: s ends at the first NUL --- */
    {
        char **res = ft_split("a b\0c d", ' ');

        total++;
        if (!res)
            fail("embedded NUL", "returned NULL");
        else
        {
            size_t n = 0;

            while (n < 5 && res[n])
                n++;
            if (n != 2 || strcmp(res[0], "a") || strcmp(res[1], "b"))
                fail("embedded NUL", "must stop at the first NUL");
            if (n < 5)
                free_words(res, n);
        }
    }

    /* --- large inputs --- */
    {
        size_t n = 100000;
        char *s = malloc(n + 3);
        char *exp = malloc(n + 3);

        memset(s, 'a', n);
        s[n] = ' ';
        s[n + 1] = 'b';
        s[n + 2] = '\0';
        memcpy(exp, s, n);
        exp[n] = '|';
        exp[n + 1] = 'b';
        exp[n + 2] = '\0';
        check("one 100 000 char word + one more", s, ' ', exp);
        free(s);
        free(exp);
    }
    {
        size_t words = 100000;
        char *s = malloc(words * 2 + 1);
        char *exp = malloc(words * 2 + 1);

        for (size_t i = 0; i < words; i++)
        {
            s[i * 2] = 'a';
            s[i * 2 + 1] = ' ';
            exp[i * 2] = 'a';
            exp[i * 2 + 1] = '|';
        }
        s[words * 2] = '\0';
        exp[words * 2 - 1] = '\0';
        check("100 000 words", s, ' ', exp);
        free(s);
        free(exp);
    }

    /* --- exhaustive sweep: every string of length 0..8 over {a, b, ','} and
           over {a, ',', ' '} with ',' as delimiter, against the reference --- */
    {
        const char *alphabets[2] = {"ab,", "a, "};
        char s[10];
        char exp[32];
        char name[64];

        for (int a = 0; a < 2; a++)
            for (int len = 0; len <= 8; len++)
            {
                int combos = 1;

                for (int k = 0; k < len; k++)
                    combos *= 3;
                for (int c = 0; c < combos; c++)
                {
                    int v = c;

                    for (int k = 0; k < len; k++)
                    {
                        s[k] = alphabets[a][v % 3];
                        v /= 3;
                    }
                    s[len] = '\0';
                    ref_expected(s, ',', exp);
                    snprintf(name, sizeof name, "sweep \"%s\"", s);
                    check(name, s, ',', exp);
                }
            }
    }

    /* --- repeated calls: no hidden state, no leaks --- */
    for (int i = 0; i < 1000; i++)
    {
        char **r = ft_split("hello big world", ' ');

        if (!r || !r[0] || !r[1] || !r[2] || r[3]
            || strcmp(r[0], "hello") || strcmp(r[1], "big")
            || strcmp(r[2], "world"))
        {
            fail("1000 repeated calls", "wrong result");
            break;
        }
        free_words(r, 3);
    }
    total++;

    /* --- NULL string: the subject does not define it, so it is only
           reported. Opt in with: ./a.out null --- */
    if (argc > 1 && strcmp(argv[1], "null") == 0)
    {
        char **r = ft_split(NULL, ' ');

        printf("INFO  ft_split(NULL, ' ') -> %s\n", r ? "non-NULL" : "NULL");
        free(r);
    }

    /* --- a failing malloc at ANY point: NULL returned, nothing leaked --- */
    check_failures("fail: three words", "a b c", ' ', "a|b|c");
    check_failures("fail: four longer words", "hello world foo bar", ' ',
                   "hello|world|foo|bar");
    check_failures("fail: one word", "abc", ' ', "abc");
    check_failures("fail: padded word", "  a  ", ' ', "a");
    check_failures("fail: empty string", "", ' ', "");
    check_failures("fail: only delimiters", "   ", ' ', "");
    check_failures("fail: two words", "x y", ' ', "x|y");
    check_failures("fail: many words", "1 2 3 4 5 6 7 8 9 10 11 12", ' ',
                   "1|2|3|4|5|6|7|8|9|10|11|12");


    printf("%d/%d passed\n", total - fails, total);
    return fails != 0;
}