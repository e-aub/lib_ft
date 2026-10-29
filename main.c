
#include "./libft.h"
#include <stdio.h>




#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>
#include <limits.h>


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "./libft.h"

#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
    int a = 1337;
    int *addr = &a;

    int *b = (int *)((char *)addr + 1);


    printf("%p\n", addr);
    printf("%p\n", b);
    printf("%d\n", *b);
    printf("%zu\n", alignof(size_t));
}