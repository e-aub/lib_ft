
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

    char *s = "xxxx";
    char *set = "x";

    char *res = ft_strtrim(s, set);
    printf("%s\n", res);
    free(res);
}