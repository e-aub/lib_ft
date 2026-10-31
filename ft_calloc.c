/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayouel-h <ayouel-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 20:50:48 by ayouel-h          #+#    #+#             */
/*   Updated: 2026/10/31 20:50:49 by ayouel-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total;
	void	*allo;

	if (size != 0 && nmemb > SIZE_MAX / size)
	{
		return (NULL);
	}
	total = nmemb * size;
	allo = malloc(total);
	if (allo == NULL)
	{
		if (total == 0)
		{
			return (malloc(1));
		}
		return (NULL);
	}
	ft_bzero(allo, total);
	return (allo);
}
