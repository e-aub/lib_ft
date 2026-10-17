
#include "./libft.h"
#include <stdio.h>

#include <string.h>
#include <unistd.h>

int main(){
    char in [6] = "abcd";
    char *c = ft_strchr(in, '\0');
    printf("%s\n", c);
}
