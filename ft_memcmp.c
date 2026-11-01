/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayouel-h <ayouel-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 22:22:52 by ayouel-h          #+#    #+#             */
/*   Updated: 2026/11/01 15:11:35 by ayouel-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t					i;
	const unsigned char		*uc_s2;
	const unsigned char		*uc_s1;

	i = 0;
	uc_s2 = (const unsigned char *)s2;
	uc_s1 = (const unsigned char *)s1;
	while (i < n)
	{
		if (uc_s1[i] != uc_s2[i])
		{
			return (uc_s1[i] - uc_s2[i]);
		}
		i++;
	}
	return (0);
}
