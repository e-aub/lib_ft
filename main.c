#include "./libft.h"
#include <stdio.h>
#include <string.h>

int main(){
    // int a = 10;
    // printf("%zu", ft_strlen(""));
    char src [] = "hello";
    char dst[10];
    ft_memcpy(dst, src, 5);

    printf("%s\n", dst);
}
