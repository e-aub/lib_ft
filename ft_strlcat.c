#include "./libft.h"

size_t  ft_strlcat(char *dst, const char *src, size_t size){
    size_t src_len;
    size_t dst_len;

	src_len = ft_strlen(src);
    dst_len = ft_strlen(dst);
	if (size)
	{
		return (src_len + dst_len);
	}
}