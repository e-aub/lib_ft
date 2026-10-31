#include "./libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char uc = (unsigned char)c;

	unsigned char *ptr = (unsigned char *)s;

	size_t i = 0;

	while (i < n)
	{
		ptr[i] = uc;
		i++;
	}

	return (s);
}