
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

int	main(void)
{
	unsigned int	start;
	size_t			len;
	char *src_ptr = "We are supercalifragilisticexpialidocious!";

	printf("Source: '%s'\n\n",src_ptr);

	start = 7;
	len = 9;
	printf("start: %d\n", start);
	printf("length: %zu\n", len);
	printf("Substring: '%s'\n\n",ft_substr(src_ptr, start, len));

	start = 7;
	len = 99;
	printf("start: %d\n", start);
	printf("length: %zu\n", len);
	printf("Substring: '%s'\n\n",ft_substr(src_ptr, start, len));

	start = 99;
	len = 7;
	printf("start: %d\n", start);
	printf("length: %zu\n", len);
	printf("Substring: '%s'\n\n",ft_substr(src_ptr, start, len));

	start = 7;
	len = 9;
	src_ptr = NULL;
	printf("Source: '%s'\n",src_ptr);
	printf("start: %d\n", start);
	printf("length: %zu\n", len);
	printf("Substring: '%s'\n",ft_substr(src_ptr, start, len));

	return (0);
}