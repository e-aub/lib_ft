#include "./libft.h"

char *ft_strnstr(const char *big, const char *little, size_t len){
    size_t big_len = ft_strlen(big);
    size_t little_len = ft_strlen(little);

    if (len < big_len){
        big_len = len;
    }

    size_t i = 0;
    size_t j = 0;

    while(i < big_len - little_len){
        if (little[j] == '\0'){
            return big[i + j];
        }else if(big[i + j] == little[j]){
            j++;
        }else{
            j = 0;
        }
        i++;
    }
    return 0;
}