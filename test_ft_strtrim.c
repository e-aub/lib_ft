#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *ft_strtrim(char const *s1, char const *set);

/*
** Optional: test malloc failure.
**   cc -g -DTEST_MALLOC_FAIL -Wl,--wrap=malloc test_strtrim.c ft_strtrim.c ...
*/
#ifdef TEST_MALLOC_FAIL
extern void *__real_malloc(size_t n);
static int g_fail_next = 0;

void *__wrap_malloc(size_t n)
{
    if (g_fail_next)
    {
        g_fail_next = 0;
        return NULL;
    }
    return __real_malloc(n);
}
#endif

static int total = 0;
static int fails = 0;

static void fail(const char *name, const char *why)
{
    fails++;
    printf("FAIL  %-40s %s\n", name, why);
    fflush(stdout);   /* make sure the line appears even if a crash follows */
}

/* Independent reference: a 256-entry membership table instead of strchr. */
static void ref_trim(const char *s1, const char *set, char *out)
{
    unsigned char in_set[256] = {0};
    size_t start = 0;
    size_t end = strlen(s1);

    for (const unsigned char *p = (const unsigned char *)set; *p; p++)
        in_set[*p] = 1;
    while (s1[start] && in_set[(unsigned char)s1[start]])
        start++;
    while (end > start && in_set[(unsigned char)s1[end - 1]])
        end--;
    memcpy(out, s1 + start, end - start);
    out[end - start] = '\0';
}

/* Runs one case. Both inputs are copied into exact-size heap buffers so ASan
   flags any read past their NUL. */
static void check(const char *name, const char *s1, const char *set,
                  const char *expected)
{
    size_t l1 = strlen(s1);
    size_t ls = strlen(set);
    size_t le = strlen(expected);
    char *a = malloc(l1 + 1);
    char *b = malloc(ls + 1);
    char *res;

    memcpy(a, s1, l1 + 1);
    memcpy(b, set, ls + 1);
    res = ft_strtrim(a, b);
    total++;
    if (!res)
    {
        fail(name, "returned NULL (expected a string)");
        free(a);
        free(b);
        return;
    }
    if (res >= a && res <= a + l1)
    {
        fail(name, "points inside s1 (no new allocation)");
        free(a);
        free(b);
        return;   /* res belongs to a: do not free it a second time */
    }
    if (strcmp(res, expected) != 0)
    {
        char msg[300];

        snprintf(msg, sizeof msg, "expected \"%s\", got \"%s\"", expected, res);
        fail(name, msg);
    }
    /* the block must hold at least le + 1 bytes */
    memset(res, 'x', le + 1);
    free(a);   /* the result must not depend on the inputs */
    free(b);
    free(res);
}

int main(int argc, char **argv)
{
    /* --- normal trimming --- */
    check("both ends, spaces", "  hello  ", " ", "hello");
    check("both ends, letters", "xxhixx", "x", "hi");
    check("start only", "xxhi", "x", "hi");
    check("end only", "hixx", "x", "hi");
    check("several different set chars", "abchelloabc", "abc", "hello");
    check("set order does not matter", "abchelloabc", "cba", "hello");
    check("set has duplicates", "xxhixx", "xxxx", "hi");
    check("mixed chars at both ends", "aabbcc-mid-ccbbaa", "abc", "-mid-");
    check("trim stops at first non-set char", "hello world", "hld", "ello wor");
    check("set char at end, not start", "hello", "lo", "he");
    check("both ends, partial overlap", "ollehol", "ol", "eh");

    /* --- interior characters must remain --- */
    check("interior set chars remain", "xxhixxhixx", "x", "hixxhi");
    check("interior hyphens remain", "a-b-c", "ac", "-b-");
    check("'-' is a plain char, not a range", "a-b-c", "a-c", "b");
    check("set char only in the middle", "abc", "b", "abc");
    check("set char surrounded by others", "xax", "x", "a");

    // /* --- nothing to trim: still a NEW copy --- */
    check("nothing to trim", "hello", "x", "hello");
    check("set chars not present", "hello", "xyz", "hello");
    check("empty set", "hello", "", "hello");
    check("one char, not in set", "x", "y", "x");

    // /* --- everything trimmed: empty string, never NULL --- */
    check("all chars in set", "xxxx", "x", "");
    check("all chars, several set chars", "abcabc", "abc", "");
    check("one char, in set", "x", "x", "");
    check("s1 equals set", "hello", "hello", "");
    check("set is a superset of s1", "ab", "abcdefgh", "");
    check("s1 uses every set char", "hello", "helo", "");

    // /* --- empty inputs --- */
    check("empty s1", "", "x", "");
    check("empty s1 and empty set", "", "", "");
    check("empty s1, long set", "", "abcdefg", "");

    /* --- case sensitivity --- */
    check("case sensitive, no match", "Hello", "h", "Hello");
    check("case sensitive, match", "Hello", "H", "ello");

    // /* --- whitespace and special characters --- */
    check("all six whitespace chars", "  \t\n hi \n\t  ", " \t\n", "hi");
    check("vertical tab / form feed / CR", "\v\f\rhi\r\f\v", "\v\f\r", "hi");
    check("only newlines", "\n\nhi\n", "\n", "hi");
    check("punctuation", "...hi...", ".", "hi");
    check("sentence", "  Hello, World!  ", " !", "Hello, World");
    check("high-bit bytes (signed char)", "\xe9hi\xe9", "\xe9", "hi");
    check("0xFF byte", "\xffhi\xff", "\xff", "hi");

    /* --- NUL inside the buffer: s1 ends at the first NUL --- */
    {
        char *res = ft_strtrim("xxab\0cdxx", "x");

        total++;
        if (!res)
            fail("embedded NUL in s1", "returned NULL");
        else
        {
            if (strcmp(res, "ab") != 0)
                fail("embedded NUL in s1", "must stop at the first NUL");
            free(res);
        }
    }

    /* --- long strings --- */
    {
        size_t n = 100000;
        char *big = malloc(n + 1);
        char *exp = malloc(n + 1);

        memset(big, 'x', 5000);
        memset(big + 5000, 'a', 90000);
        memset(big + 95000, 'x', 5000);
        big[n] = '\0';
        memset(exp, 'a', 90000);
        exp[90000] = '\0';
        check("100 000 chars, trim 5 000 each side", big, "x", exp);

        memset(big, 'x', n);
        big[n] = '\0';
        check("100 000 chars, all trimmed", big, "x", "");
        free(big);
        free(exp);
    }

    // /* --- exhaustive sweep: every s1 over "abc" (length 0..6) against every
    //        subset of "abcd", in normal and reversed+duplicated order --- */
    {
        const char *letters = "abcd";
        char s1[8];
        char set1[16];
        char set2[16];
        char expected[16];
        char name[80];

        for (int len = 0; len <= 6; len++)
        {
            int combos = 1;

            for (int k = 0; k < len; k++)
                combos *= 3;
            for (int c = 0; c < combos; c++)
            {
                int v = c;

                for (int k = 0; k < len; k++)
                {
                    s1[k] = (char)('a' + v % 3);
                    v /= 3;
                }
                s1[len] = '\0';
                for (int mask = 0; mask < 16; mask++)
                {
                    int p = 0;
                    int q = 0;

                    for (int k = 0; k < 4; k++)
                        if (mask & (1 << k))
                            set1[p++] = letters[k];
                    set1[p] = '\0';
                    for (int k = 3; k >= 0; k--)
                        if (mask & (1 << k))
                        {
                            set2[q++] = letters[k];
                            set2[q++] = letters[k];
                        }
                    set2[q] = '\0';
                    ref_trim(s1, set1, expected);
                    snprintf(name, sizeof name, "sweep s1=\"%s\" set=\"%s\"",
                             s1, set1);
                    check(name, s1, set1, expected);
                    snprintf(name, sizeof name, "sweep s1=\"%s\" set=\"%s\"",
                             s1, set2);
                    check(name, s1, set2, expected);
                }
            }
        }
    }

    /* --- many allocations: leaks show up as LeakSanitizer reports --- */
    for (int i = 0; i < 1000; i++)
    {
        char *r = ft_strtrim("  hello  ", " ");

        if (!r || strcmp(r, "hello") != 0)
        {
            fail("1000 repeated calls", "wrong result");
            free(r);
            break;
        }
        free(r);
    }
    (void) argv;
    (void) argc;
    total++;

    /* --- NULL arguments: the subject does not define these, so the result
           is only reported, never counted. Opt in with: ./a.out null --- */
    if (argc > 1 && strcmp(argv[1], "null") == 0)
    {
        char *r1 = ft_strtrim(NULL, "x");
        char *r2 = ft_strtrim("hello", NULL);

        printf("INFO  ft_strtrim(NULL, \"x\")    -> %s\n",
               r1 ? "non-NULL" : "NULL");
        printf("INFO  ft_strtrim(\"hello\", NULL) -> %s\n",
               r2 ? r2 : "NULL");
        free(r1);
        free(r2);
    }

#ifdef TEST_MALLOC_FAIL
    g_fail_next = 1;
    total++;
    if (ft_strtrim("  hello  ", " ") != NULL)
        fail("malloc failure", "expected NULL");
    g_fail_next = 1;
    total++;
    if (ft_strtrim("xxxx", "x") != NULL)
        fail("malloc failure, empty result", "expected NULL");
#endif

    printf("%d/%d passed\n", total - fails, total);
    return fails != 0;
}