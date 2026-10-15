#include "./libft.h"
#include <stdio.h>
#include <string.h>

int main(){
    // int a = 10;
    // printf("%zu", ft_strlen(""));

//     printf("%s\n", "CASE1: ______________________");

//     char src [] = "hello";
//     ft_memmove(src, &src[2], 2);

//     printf("ft_memmove: %s\n", src);

//     char src1 [] = "hello";
//     memmove(src1, &src1[2], 2);

//     printf("original_memmove: %s\n", src1);


//    {
//     printf("%s\n", "CASE2: ______________________");

//     char src [] = "hello";
//     char dst [100];

//     ft_memmove(dst, src, 5);

//     printf("ft_memmove: %s\n", dst);

//     char src1 [] = "hello";
//     char dst1 [100];


//     memmove(dst1, src1, 5);

//     printf("original_memmove: %s\n", dst1);

//     }


    char buffer[] = "0123456789";
    //0103456789
    //0101456789
    //01010
    // char dst[300] = "sssssssssxxxxxxs";
    ft_memmove(&buffer[2], buffer, 5);
    //


    //o world
    //c

    printf("%s\n", buffer);
}


// 0   4 // 1 4

