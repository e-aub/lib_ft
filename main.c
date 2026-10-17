
#include "./libft.h"
#include <stdio.h>

#include <string.h>
#include <unistd.h>

int main(){
    int s = 1;
    {
        char *src = " World";
        char dest[9] = "";
        dest[5] = 'k';
        size_t expected = ft_strlcat(dest, src, s);
        
        printf("expected: %zu, new_dst: %s\n", expected, dest);
        
    }
    
    {
        char *src = " World";
        char dest[9] = "";
        dest[5] = 'k';
        size_t expected = strlcat(dest, src, s);
        
        printf("expected: %zu, new_dst: %s\n", expected, dest);
        
    }
}
