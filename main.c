
#include "./libft.h"
#include <stdio.h>

#include <string.h>
#include <unistd.h>

#include <stdio.h>
#include <string.h>

#include <stdio.h>
#include <string.h>
#include <stddef.h>

int main(void)
{
	char str[] = "Hello, World!";

    void *res = memchr(str, 'o', 4);
    void *res2 = ft_memchr(str, 'o', 4);

        printf("_____________________\n%s", (char *)res);
        printf("_____________________\n%s", (char *)res2);
}