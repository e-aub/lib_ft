/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayouel-h <ayouel-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 10:56:58 by ayouel-h          #+#    #+#             */
/*   Updated: 2026/10/15 11:00:39 by ayouel-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*t_dest;
	const unsigned char	*t_src;

	if (dest == src || n == 0)
	{
		return (dest);
	}
	t_dest = (unsigned char *)dest;
	t_src = (const unsigned char *)src;
	if (src < dest)
	{
		while (n > 0)
		{
			n--;
			*(t_dest + n) = *(t_src + n);
		}
	}
	else
	{
		ft_memcpy(t_dest, t_src, n);
	}
	return (dest);
}
