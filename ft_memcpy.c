#include "./libft.h"
void *ft_memcpy(void *dest, const void *src, size_t n){
    const unsigned char *uc_src = src;
    unsigned char *uc_dest = dest;

    size_t i = 0;

    while(i < n){
        *uc_dest = *uc_src;
        uc_src++;
        uc_dest++;
        i++;
    }
    return dest;
}