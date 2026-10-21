
#include "./libft.h"
#include <stdio.h>




#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>
#include <limits.h>

static int  check_zero(const void *ptr, size_t total)
{
    const unsigned char *bytes;
    size_t              i;

    if (ptr == NULL)
        return (0);
    bytes = (const unsigned char *)ptr;
    i = 0;
    while (i < total)
    {
        if (bytes[i] != 0)
            return (0);
        i++;
    }
    return (1);
}

static void test_case(size_t nmemb, size_t size)
{
    void    *original;
    void    *mine;
    size_t  total;
    int     original_null;
    int     mine_null;
    int     same_result;

    total = nmemb * size;
    errno = 0;
    original = calloc(nmemb, size);
    original_null = (original == NULL);
    errno = 0;
    mine = ft_calloc(nmemb, size);
    mine_null = (mine == NULL);
    same_result = 1;

    if (original_null != mine_null)
        same_result = 0;
    if (!original_null && total <= 1000000)
    {
        if (!check_zero(original, total) || !check_zero(mine, total))
            same_result = 0;
        if (memcmp(original, mine, total) != 0)
            same_result = 0;
    }
    printf("%s | nmemb=%zu size=%zu total=%zu | libc=%p ft=%p\n",
        same_result ? "PASS" : "FAIL",
        nmemb, size, total, original, mine);
    free(original);
    free(mine);
}

int main(void)
{
    size_t max;

    max = SIZE_MAX;
    printf("=== Basic cases ===\n");
    test_case(0, 0);
    test_case(0, 1);
    test_case(1, 0);
    test_case(1, 1);
    test_case(1, 10);

    unsigned char *original = (unsigned char *)ft_calloc(1, 10);
    (void) original;
    // size_t i = 0;
    // while (i < 10)
    // {
    //     printf("%d, ", original[i]);
    //     i++;
    // }

    

    test_case(10, 1);
    test_case(10, 10);
    test_case(100, 100);
    test_case(1024, 1024);

    printf("\n=== Different element sizes ===\n");
    test_case(7, sizeof(char));
    test_case(7, sizeof(int));
    test_case(7, sizeof(long));
    test_case(7, sizeof(void *));
    test_case(3, 17);
    test_case(17, 3);

    printf("\n=== Large allocation requests ===\n");
    test_case(max, 1);
    test_case(max / 2, 2);
    test_case(max / 2 + 1, 2);
    test_case(max, 2);
    test_case(max / 4 + 1, 4);
    test_case(max / 8 + 1, 8);

    printf("\n=== Boundary multiplication cases ===\n");
    test_case(max / 2, 2);
    test_case(max / 2 + 1, 2);
    test_case(max / 3, 3);
    test_case(max / 3 + 1, 3);
    test_case(max / 10, 10);
    test_case(max / 10 + 1, 10);

    return (0);
}
