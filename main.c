
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

static int  g_tests = 0;
static int  g_failed = 0;

void    test_strdup(const char *input, const char *name)
{
    char    *original;
    char    *custom;
    int     same_content;
    int     separate_memory;

    original = strdup(input);
    custom = ft_strdup(input);
    g_tests++;

    if (original == NULL || custom == NULL)
    {
        printf("[%s] %s: allocation failed\n",
            (original == NULL && custom == NULL) ? "BOTH NULL" : "FAIL",
            name);
        if (original != NULL || custom != NULL)
            g_failed++;
        free(original);
        free(custom);
        return ;
    }

    same_content = (strcmp(original, custom) == 0);
    separate_memory = (original != custom);

    if (same_content && separate_memory)
        printf("[PASS] %s\n", name);
    else
    {
        printf("[FAIL] %s | content: %s | separate memory: %s\n",
            name,
            same_content ? "OK" : "DIFFERENT",
            separate_memory ? "YES" : "NO");
        g_failed++;
    }

    free(original);
    free(custom);
}

int main(void)
{
    char    empty[] = "";
    char    one[] = "a";
    char    normal[] = "Hello, World!";
    char    spaces[] = "   ";
    char    digits[] = "0123456789";
    char    punctuation[] = "!@#$%^&*()_+-=[]{};':\",./<>?";
    char    escaped[] = "\t\n\r\v\f\a\b";
    char    embedded[] = {'a', 'b', '\0', 'c', 'd', '\0'};
    char    long_string[10001];
    int     i;

    printf("=== Basic cases ===\n");
    test_strdup(empty, "Empty string");
    test_strdup(one, "Single character");
    test_strdup(normal, "Normal sentence");
    test_strdup("Hello", "Short literal");
    test_strdup("a", "Single letter literal");
    test_strdup(" ", "Single space");
    test_strdup(spaces, "Multiple spaces");

    printf("\n=== Character variety ===\n");
    test_strdup(digits, "Digits");
    test_strdup(punctuation, "Punctuation");
    test_strdup(escaped, "Whitespace and control characters");
    test_strdup("UPPER lower MiXeD", "Mixed case");
    test_strdup("cafe", "Plain ASCII text");
    test_strdup("line1\nline2", "Newline inside string");
    test_strdup("tab\there", "Tab inside string");

    printf("\n=== String boundaries ===\n");
    test_strdup(embedded, "Embedded null terminator");
    test_strdup("a\0ignored", "Literal with embedded null");
    test_strdup("end", "String ending at terminator");

    printf("\n=== Length tests ===\n");
    for (i = 0; i < 10000; i++)
        long_string[i] = 'x';
    long_string[10000] = '\0';

    test_strdup("123456789012345678901234567890",
        "30-character string");
    test_strdup(long_string, "10,000-character string");

    printf("\n=== Independent allocation tests ===\n");
    {
        char    *a;
        char    *b;

        a = ft_strdup("independent");
        b = ft_strdup("independent");
        g_tests++;
        if (a != NULL && b != NULL
            && a != b && strcmp(a, b) == 0)
            printf("[PASS] Two calls allocate independent strings\n");
        else
        {
            printf("[FAIL] Two calls allocate independent strings\n");
            g_failed++;
        }
        free(a);
        free(b);
    }

    printf("\n=== Source independence test ===\n");
    {
        char    source[] = "original";
        char    *copy;

        copy = ft_strdup(source);
        g_tests++;
        if (copy != NULL && copy != source
            && strcmp(copy, source) == 0)
        {
            source[0] = 'X';
            if (strcmp(copy, "original") == 0)
                printf("[PASS] Copy survives source modification\n");
            else
            {
                printf("[FAIL] Copy survives source modification\n");
                g_failed++;
            }
        }
        else
        {
            printf("[FAIL] Copy survives source modification\n");
            g_failed++;
        }
        free(copy);
    }

    printf("\n=== Summary ===\n");
    printf("Tests: %d\n", g_tests);
    printf("Failed: %d\n", g_failed);
    printf("Passed: %d\n", g_tests - g_failed);
    return (g_failed != 0);
}
