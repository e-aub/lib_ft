#include "./libft.h"

static size_t ft_strlen_or_n(const char * s, size_t n){
    size_t length = 0;
    while(*s && length < n){
        s++;
        length++;
    }
    return length;
}

size_t  ft_strlcat(char *dst, const char *src, size_t size){
    size_t src_len;
    size_t dst_len;

	src_len = ft_strlen(src);
    dst_len = ft_strlen_or_n(dst, size);
	if (size <= dst_len)
	{
		return (src_len + size);
	}

	size_t i = 0;

	while(src[i] && i < (size - dst_len - 1)){
		dst[dst_len + i] = src[i];
		i++;
	}

	dst[dst_len + i] = '\0';

	return src_len + dst_len;
}