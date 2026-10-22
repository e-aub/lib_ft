

#include "./libft.h"

void *ft_calloc(size_t nmemb, size_t size){

    if (size != 0 && nmemb > SIZE_MAX / size){
        return NULL;
    }

    size_t total = nmemb * size;

    void *allo = malloc(total);
    if (allo == NULL){
        return NULL;
    }
    ft_bzero(allo, total);

    return allo;
}