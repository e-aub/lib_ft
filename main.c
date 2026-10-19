
#include "./libft.h"
#include <stdio.h>


#include <stdio.h>
#include <string.h>
#include <stddef.h>

char *
strnstr(const char *s, const char *find, size_t slen)
{
	char c, sc;
	size_t len;

	if ((c = *find++) != '\0') {
		len = strlen(find);
		do {
			do {
				if (slen-- < 1 || (sc = *s++) == '\0')
					return (NULL);
			} while (sc != c);
			if (len > slen)
				return (NULL);
		} while (strncmp(s, find, len) != 0);
		s--;
	}
	return ((char *)s);
}


#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include "libft.h"

typedef struct s_test
{
	const char	*big;
	const char	*little;
	size_t		len;
}	t_test;

int	main(void)
{
	t_test	tests[] = {
		{"hello", "ll", 5},
		{"hello", "he", 5},
		{"hello", "lo", 5},
		{"hello", "o", 5},
		{"hello", "x", 5},
		{"hello", "", 5},
		{"hello", "", 0},
		{"hello", "h", 0},
		{"hello", "he", 1},
		{"hello", "he", 2},
		{"hello", "ell", 4},
		{"hello", "llo", 4},
		{"hello", "lo", 3},
		{"hello", "lo", 4},
		{"abc", "abcd", 100},
		{"abc", "bc", 3},
		{"abc", "bc", 2},
		{"", "a", 10},
		{"", "", 0},
		{"aaaaab", "aaab", 6},
		{"abababa", "ababa", 7},
		{"abababa", "babab", 7},
		{"mississippi", "issip", 11},
		{"ABC", "abc", 3},
		{"abcabc", "abc", 6},
		{"abcabc", "abc", 3},
		{"abcabc", "abc", 2},
		{"abc", "c", 3},
		{"abc", "c", 2},
		{"abcdef", "de", 4},
		{"abcdef", "de", 5},
		{"abcdef", "ef", 6},
		{"abcdef", "ef", 5},
		{"aaaa", "aa", 4},
		{"aaaa", "aaa", 4},
		{"aaaa", "aaaa", 4},
		{"aaaa", "aaaaa", 4},
		{"abc", "d", 100},
		{"abc", "bc", 100},
		{"abc", "a", 1},
		{"abc", "ab", 1},
		{"abc", "ab", 2},
		{"abc", "abc", 3},
		{"abc", "abc", 2},
		{"abc", "b", 1},
		{"abc", "b", 2},
		{"abc", "b", 3},
		{"a", "a", 1},
		{"a", "a", 0},
		{"a", "aa", 100},
		{"aaaa", "aab", 4},
		{"abcabc", "cab", 6},
		{"abcabc", "cab", 5},
		{"123456789", "456", 6},
		{"123456789", "456", 5},
		{"abcdef", "ABC", 6},
		{"abc", "c", (size_t)-1},
	};
	size_t	count;
	size_t	i;
	char	*expected;
	char	*actual;
	int		expected_offset;
	int		actual_offset;
	int		failures;

	count = sizeof(tests) / sizeof(tests[0]);
	failures = 0;
	i = 0;
	while (i < count)
	{
		expected = strnstr(tests[i].big,
				tests[i].little, tests[i].len);
		actual = ft_strnstr(tests[i].big,
				tests[i].little, tests[i].len);
		expected_offset = -1;
		actual_offset = -1;
		if (expected != NULL)
			expected_offset = (int)(expected - tests[i].big);
		if (actual != NULL)
			actual_offset = (int)(actual - tests[i].big);
		if (expected_offset != actual_offset)
		{
			printf("FAIL #%zu: big=\"%s\", little=\"%s\", len=%zu\n",
				i + 1, tests[i].big, tests[i].little, tests[i].len);
			printf("  Original offset: %d\n", expected_offset);
			printf("  Your offset:     %d\n", actual_offset);
			failures++;
		}
		else
			printf("PASS #%zu\n", i + 1);
		i++;
	}
	printf("\nTotal: %zu | Passed: %zu | Failed: %d\n",
		count, count - (size_t)failures, failures);
	return (failures != 0);
}
