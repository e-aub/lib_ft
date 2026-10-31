/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayouel-h <ayouel-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 22:15:35 by ayouel-h          #+#    #+#             */
/*   Updated: 2026/10/31 22:17:02 by ayouel-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	c_c;
	unsigned char	*c_s;

	i = 0;
	c_c = (unsigned char)c;
	c_s = (unsigned char *)s;
	if (n == 0)
	{
		return (0);
	}
	while (i < n - 1 && c_c != *(c_s + i))
	{
		i++;
	}
	if (c_c == *(c_s + i))
	{
		return ((void *)(c_s + i));
	}
	return (0);
}
