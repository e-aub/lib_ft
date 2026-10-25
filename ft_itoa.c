/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayouel-h <ayouel-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 18:58:11 by ayouel-h          #+#    #+#             */
/*   Updated: 2026/10/25 18:59:57 by ayouel-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static size_t	calculate_size(long n)
{
	size_t	size;

	size = 0;
	if (n <= 0)
		size++;
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size + 1);
}

static void	convert(long l_n, char *res, size_t i)
{
	if (l_n < 0)
	{
		res[0] = '-';
		l_n = -l_n;
	}
	if (l_n == 0)
		res[i] = '0';
	while (l_n > 0)
	{
		res[i] = (l_n % 10) + '0';
		l_n /= 10;
		if (i == 0)
			break ;
		i--;
	}
}

char	*ft_itoa(int n)
{
	long	l_n;
	size_t	size;
	char	*res;
	size_t	i;

	l_n = n;
	size = calculate_size(l_n);
	res = malloc(size);
	i = size - 1;
	if (!res)
		return (NULL);
	res[i] = '\0';
	i--;
	convert(l_n, res, i);
	return (res);
}

// int main(){
// 	printf("%s\n", ft_itoa(1000000200));
// }