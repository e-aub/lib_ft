#include "./libft.h"
#include <unistd.h>

int main(){
    write(1, ft_isprint(31) ? "1" : "0", 1);
}