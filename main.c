
#include "./libft.h"
#include <stdio.h>


#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


int	ft_atoi(const char *str);


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stddef.h>

int ft_atoi(const char *str);

typedef struct s_test
{
    const char  *name;
    const char  *input;
    int         undefined;
}   t_test;

int main(void)
{
    t_test tests[] = {
        /* Basic conversions */
        {"zero", "0", 0},
        {"positive", "42", 0},
        {"negative", "-42", 0},
        {"plus sign", "+42", 0},
        {"negative zero", "-0", 0},
        {"positive zero", "+0", 0},
        {"leading zeros", "0000042", 0},
        {"many leading zeros", "00000000000000000042", 0},
        {"zero with suffix", "000abc", 0},

        /* INT boundaries: 32-bit int */
        {"INT_MAX", "2147483647", 0},
        {"INT_MAX - 1", "2147483646", 0},
        {"INT_MAX - 2", "2147483645", 0},
        {"INT_MIN", "-2147483648", 0},
        {"INT_MIN + 1", "-2147483647", 0},
        {"INT_MIN + 2", "-2147483646", 0},
        {"INT_MAX + 1", "2147483648", 1},
        {"INT_MAX + 2", "2147483649", 1},
        {"INT_MAX + 10", "2147483657", 1},
        {"INT_MIN - 1", "-2147483649", 1},
        {"INT_MIN - 2", "-2147483650", 1},
        {"INT_MIN - 10", "-2147483658", 1},

        /* Long boundaries: 64-bit long */
        {"LONG_MAX", "9223372036854775807", 1},
        {"LONG_MIN", "-9223372036854775808", 1},
        {"LONG_MAX + 1", "9223372036854775808", 1},
        {"LONG_MIN - 1", "-9223372036854775809", 1},

        /* Huge numbers */
        {"many positive digits",
            "99999999999999999999", 1},
        {"many negative digits",
            "-99999999999999999999", 1},
        {"very long positive",
            "1234567890123456789012345678901234567890", 1},
        {"very long negative",
            "-1234567890123456789012345678901234567890", 1},
        {"100 zeros then 1",
            "0000000000000000000000000000000000000001", 0},

        /* Empty and missing digits */
        {"empty", "", 0},
        {"single space", " ", 0},
        {"multiple spaces", "     ", 0},
        {"letters", "abc", 0},
        {"letters then digits", "abc123", 0},
        {"punctuation", "!@#$", 0},
        {"only plus", "+", 0},
        {"only minus", "-", 0},
        {"plus then letter", "+a", 0},
        {"minus then letter", "-a", 0},
        {"sign then space", "+ 42", 0},
        {"space then sign", "  - 42", 0},

        /* Whitespace */
        {"space", " 42", 0},
        {"tab", "\t42", 0},
        {"newline", "\n42", 0},
        {"vertical tab", "\v42", 0},
        {"form feed", "\f42", 0},
        {"carriage return", "\r42", 0},
        {"mixed whitespace", " \t\n\v\f\r42", 0},
        {"spaces then negative", "   -42", 0},
        {"trailing spaces", "42   ", 0},
        {"trailing tabs", "42\t\t", 0},
        {"newline suffix", "42\n99", 0},

        /* Signs */
        {"double plus", "++42", 0},
        {"double minus", "--42", 0},
        {"plus then minus", "+-42", 0},
        {"minus then plus", "-+42", 0},
        {"embedded plus", "12+34", 0},
        {"embedded minus", "12-34", 0},
        {"sign after digits", "42-3", 0},
        {"plus with zeros", "+00042", 0},
        {"minus with zeros", "-00042", 0},
        {"plus plus zero", "++0", 0},

        /* Trailing characters */
        {"digits then letters", "123abc", 0},
        {"negative then letters", "-123abc", 0},
        {"decimal point", "123.456", 0},
        {"comma", "12,34", 0},
        {"hex-like", "0x2A", 0},
        {"binary-like", "0b101", 0},
        {"multiple numbers", "12 34", 0},
        {"digits then punctuation", "123!@#", 0},
        {"number with suffix", "42xyz99", 0},
        {"leading punctuation", ".42", 0},
        {"leading slash", "/42", 0},

        /* Leading zeros around boundaries */
        {"zero-padded INT_MAX",
            "0002147483647", 0},
        {"zero-padded INT_MIN",
            "-0002147483648", 0},
        {"zero-padded overflow",
            "0002147483648", 1},
        {"negative zero-padded overflow",
            "-0002147483649", 1},

        /* Sign and boundary combinations */
        {"plus INT_MAX", "+2147483647", 0},
        {"plus INT_MAX + 1", "+2147483648", 1},
        {"minus INT_MIN", "-2147483648", 0},
        {"plus INT_MIN magnitude", "+2147483648", 1},

        /* Overflow after a long zero prefix */
        {"zeros then overflow",
            "000000000000000000002147483648", 1},
        {"negative zeros then overflow",
            "-000000000000000000002147483649", 1},

        /* Signs and suffixes on out-of-range numbers */
        {"overflow with suffix", "2147483648abc", 1},
        {"negative overflow with suffix", "-2147483649abc", 1},
        {"huge overflow with suffix",
            "99999999999999999999abc", 1},

        /* Inputs with embedded whitespace */
        {"space inside number", "12 34", 0},
        {"tab inside number", "12\t34", 0},
        {"space before suffix", "12 abc", 0},

        /* Explicitly malformed input */
        {"only punctuation", "...", 0},
        {"sign and punctuation", "-!", 0},
        {"whitespace and letters", "  abc123", 0},
        {"whitespace then sign only", "  +", 0}
    };

    size_t  i;
    size_t  count;
    int     original;
    int     mine;
    int     failures;
    int     defined_tests;
    int     undefined_tests;

    count = sizeof(tests) / sizeof(tests[0]);
    failures = 0;
    defined_tests = 0;
    undefined_tests = 0;

    printf("int:  [%d, %d]\n", INT_MIN, INT_MAX);
    printf("long: [%ld, %ld]\n\n", LONG_MIN, LONG_MAX);

    printf("%-31s | %-12s | %-12s | %s\n",
        "TEST", "atoi", "ft_atoi", "RESULT");
    printf("--------------------------------------------------------------------------\n");

    for (i = 0; i < count; i++)
    {
        /*
         * Overflow cases are experiments only.
         * The C standard does not define atoi's result
         * when the converted value cannot fit in int.
         */
        original = atoi(tests[i].input);
        mine = ft_atoi(tests[i].input);

        printf("%-31s | %-12d | %-12d | ",
            tests[i].name, original, mine);

        if (tests[i].undefined)
        {
            printf("UNDEFINED BEHAVIOR\n");
            undefined_tests++;
        }
        else if (original == mine)
        {
            printf("PASS\n");
            defined_tests++;
        }
        else
        {
            printf("FAIL\n");
            failures++;
            defined_tests++;
        }
    }

    printf("--------------------------------------------------------------------------\n");
    printf("Defined tests:   %d\n", defined_tests);
    printf("Undefined tests: %d (not counted as PASS/FAIL)\n",
        undefined_tests);
    printf("Defined mismatches: %d\n", failures);

    return (failures != 0);
}
