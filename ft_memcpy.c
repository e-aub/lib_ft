/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayouel-h <ayouel-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 22:29:30 by ayouel-h          #+#    #+#             */
/*   Updated: 2026/10/31 22:31:25 by ayouel-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*uc_src;
	unsigned char		*uc_dest;
	size_t				i;

	uc_src = src;
	uc_dest = dest;
	i = 0;
	while (i < n)
	{
		*uc_dest = *uc_src;
		uc_src++;
		uc_dest++;
		i++;
	}
	return (dest);
}
