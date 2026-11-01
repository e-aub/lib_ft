/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayouel-h <ayouel-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 17:10:05 by ayouel-h          #+#    #+#             */
/*   Updated: 2026/11/01 15:11:35 by ayouel-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	s_len;
	size_t	sub_len;

	if (!s)
	{
		return (NULL);
	}
	s_len = ft_strlen(s);
	if (s_len <= start)
	{
		return (ft_strdup(""));
	}
	sub_len = s_len - start;
	if (len > sub_len)
	{
		len = sub_len;
	}
	sub = malloc(len + 1);
	if (sub == NULL)
	{
		return (NULL);
	}
	ft_strlcpy(sub, s + start, len + 1);
	return (sub);
}
