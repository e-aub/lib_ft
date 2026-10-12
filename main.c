#include "./libft.h"
#include <unistd.h>

int main(){
    write(1, ft_isalnum(255) ? "1" : "0", 1);
}