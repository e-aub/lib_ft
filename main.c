#include "./libft.h"
#include <stdio.h>
#include <string.h>

int main(){
    // int a = 10;
    // printf("%zu", ft_strlen(""));
    char s [] = "hello";
    int n = 48;
    // unsigned char c = (unsigned char) n;
    // printf("ascii value: %d\nchar: %s", c, &c);
    ft_memset(s, n, 6);

    memset(NULL, n, 6);

    printf("%s", s);
}
