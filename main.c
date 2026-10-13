#include "./libft.h"
#include <stdio.h>
#include <string.h>

int main(){
    // int a = 10;
    // printf("%zu", ft_strlen(""));
    char s [] = "hello";
    // int n = 48;
    // unsigned char c = (unsigned char) n;
    // printf("ascii value: %d\nchar: %s", c, &c);
    char * z = &s[2];
    ft_bzero(z, 0);

    printf("%s", s);
}
