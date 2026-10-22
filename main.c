
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

    char *h = "";
    char *w = "";

    char *res = ft_strjoin(h, w);
    printf("%s, length: %zu", res, ft_strlen(res));
    

    free(res);
}