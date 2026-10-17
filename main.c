
#include "./libft.h"
#include <stdio.h>

#include <string.h>
#include <unistd.h>

int main(){
    char *src = "Hello";
    char dest[50] = "";
    size_t expected = ft_strlcpy(dest, src, 6);

    if (expected != ft_strlen(dest)){
        printf("%s -----> expected: %zu, dest_len: %zu\n", "trunc occured", expected, ft_strlen(dest));
    }

    printf("%s\n", dest);
}

