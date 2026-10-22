#include "./libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len){
    char    *sub;
    size_t  i;
    size_t s_len;
    if(!s){
        return NULL;
    }

    s_len = ft_strlen(s);
    if(s_len <= start){
        return ft_strdup("");
    }

    size_t sub_len = s_len - start;
    if (len > sub_len){
        len = sub_len;
    }

    sub = malloc(len + 1);

    if (sub == NULL){
        return NULL;
    }

    i = 0;

    while(i < len){
        sub[i] = s[start + i];
        i++;
    }

    sub[i] = '\0';


    return sub;
}
