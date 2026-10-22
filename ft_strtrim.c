#include "./libft.h"

int	contains(char const *charset, char c)
{
	while (*charset)
	{
		if (*charset == c)
		{
			return (1);
		}
		charset++;
	}
	return (0);
}

void	look_forward(size_t *start_idx, size_t len, char const *s1,
		char const *set)
{
	while (*start_idx < len)
	{
		if (contains(set, s1[*start_idx]))
		{
			*start_idx = *start_idx + 1;
		}
		else
		{
			break ;
		}
	}
}

void	look_backward(size_t *end_idx, char const *s1, char const *set)
{
	while (*end_idx > 0)
	{
		if (contains(set, s1[*end_idx]))
		{
			*end_idx = *end_idx - 1;
		}
		else
		{
			break ;
		}
	}
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	s1_len;
	size_t	start_idx;
	size_t	end_idx;
	char	*res;
	size_t	size;

	if (!s1 || !set)
		return (NULL);
	if (!*set)
	{
		return (ft_strdup(s1));
	}
	s1_len = ft_strlen(s1);
	if (s1_len == 0)
	{
		return (ft_strdup(""));
	}
	start_idx = 0;
	end_idx = s1_len - 1;
	look_forward(&start_idx, s1_len, s1, set);
	if (start_idx > end_idx)
	{
		return (ft_strdup(""));
	}
	look_backward(&end_idx, s1, set);
	size = (end_idx - start_idx) + 2;
	res = malloc(size);
	if (!res)
	{
		return (NULL);
	}
	res[0] = '\0';
	ft_strlcat(res, s1 + start_idx, size);
	return (res);
}
