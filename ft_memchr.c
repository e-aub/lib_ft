#include "./libft.h"

void *ft_memchr(const void *s, int c, size_t n){
    size_t i = 0;
    unsigned char c_c = (unsigned char) c;
    unsigned char *c_s = (unsigned char *)s;

    if(n == 0){
        return 0;
    }

    while(i < n - 1 && c_c != *(c_s + i)){
        i++;
    }

    if (c_c == *(c_s + i)){
        return (void *)(s+i);
    }

    return 0;
}