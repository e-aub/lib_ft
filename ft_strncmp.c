#include "./libft.h"

int ft_strncmp(const char *s1, const char *s2, size_t n){
    size_t i = 0;

    if (n == 0){
        return 0;
    }

    unsigned char *c_s1 = (unsigned char *)(s1);
    unsigned char *c_s2 = (unsigned char *)(s2);


    while(*c_s1 && *c_s2 && i < (n - 1) &&  *c_s1 == *c_s2){
        i++;
        c_s1 = (unsigned char *)(s1 + i);
        c_s2 = (unsigned char *)(s2 + i);
    }

    return *c_s1 - *c_s2;
}