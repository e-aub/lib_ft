
#include "./libft.h"
#include <stdio.h>


#include <stdio.h>
#include <string.h>
#include <stddef.h>

int main(void)
{
	struct test
    {
        int a;
    };
    

    struct test instance_test = {
        .a = 1
    };

    struct test instance_test1 = {
        .a = 1
    };

    
	// char str1[] = "Hello, World!";


    int res2 = ft_memcmp(&instance_test, &instance_test1, sizeof(struct test) + 3);
    int res = memcmp(&instance_test, &instance_test1, sizeof(struct test) + 3);

        printf("_____________________\n%d", res);
        printf("_____________________\n%d", res2);
}