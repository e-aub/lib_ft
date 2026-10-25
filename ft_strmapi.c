
#include "./libft.h"


char f(unsigned int index, char c)
{
    if (index % 2 == 0)
        return (c - 32);
    return (c);
}

char *ft_strmapi(char const *s, char (*f)(unsigned int, char)){
    size_t len = ft_strlen(s);
    size_t i = 0;

    char *res = malloc(sizeof(char) * (len + 1));
    if(!res)
        return (NULL);
    
    while(i < len){
        res[i] = f(i, res[i]);
        i++;
    }
    res[i] = '\0';
    return res;
}

int main(){
    char *str = "abcdef";
    char *res = ft_strmapi(str, f);
    printf("%s\n", res);
}