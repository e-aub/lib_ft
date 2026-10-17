
#include "./libft.h"
#include <stdio.h>

#include <string.h>
#include <unistd.h>

int main(){
    char in [10] = "abcadcÆ";
    char *c = ft_strrchr(in, 198);
    printf("%s\n", c);


    char *z = strrchr(in, 198);
    printf("original: %s\n", z);
}
