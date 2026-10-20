#include "./libft.h"

int	ft_isspace(char c)
{
	return (c == 32) || (c >= 9 && c <= 13);
}

void	skip_space(const char **nptr)
{
	while (**nptr && ft_isspace(**nptr))
		*nptr = *nptr + 1;
}

void	derive_sign(const char **nptr, int *sign)
{
	if (**nptr)
	{
		if (**nptr == '-')
		{
			*sign = -1;
			*nptr = *nptr + 1;
		}
		else if (**nptr == '+')
		{
			*nptr = *nptr + 1;
		}
	}
}

int	is_overflow(int sign, long *res, int to_add)
{
	if (sign == 1 && *res > ((LONG_MAX)-to_add) / 10)
	{
		*res = LONG_MAX;
		return (1);
	}
	else if (sign == -1 && (unsigned long)*res > (((LONG_MAX + (unsigned long)1)) - to_add)
		/ 10)
	{
		*res = LONG_MIN;
		return (1);
	}
	return (0);
}

int	ft_atoi(const char *nptr)
{
	long	res;
	int		sign;

	res = 0;
    sign = 1;
	skip_space(&nptr);
	derive_sign(&nptr, &sign);
	while (*nptr && (*nptr >= '0' && *nptr <= '9'))
	{
		if (is_overflow(sign, &res, (*nptr - 48)))
		{
			return (int)(res);
		}
		else
		{
			res = (res * 10) + (*nptr - 48);
		}
		nptr++;
	}
	return (int)(res * sign);
}


// int main(){
//     printf("%d\n", ft_atoi("42"));
// }