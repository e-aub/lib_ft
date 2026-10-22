
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

int main(void)
{
    void *res = calloc(0, 0);

    printf("Pointer: %p\n", res);

    if (res != NULL){
        printf("pointer to res: %d\n", *(unsigned char *)res);
    }



    free(NULL);
    return 0;
}