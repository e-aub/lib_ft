/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayouel-h <ayouel-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 20:19:58 by ayouel-h          #+#    #+#             */
/*   Updated: 2026/11/01 15:11:35 by ayouel-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last;
	char	c_c;

	last = 0;
	c_c = (char)c;
	while (*s)
	{
		if (*s == c_c)
		{
			last = (char *)s;
		}
		s++;
	}
	if (*s == c_c)
	{
		last = (char *)s;
	}
	return (last);
}
