/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayouel-h <ayouel-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 19:01:12 by ayouel-h          #+#    #+#             */
/*   Updated: 2026/10/23 19:02:12 by ayouel-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

size_t	calcuate_words(char const *s, char c)
{
	size_t			tot;
	unsigned char	prev_is_sep;

	tot = 0;
	prev_is_sep = 1;
	while (*s)
	{
		if (*s == c)
			prev_is_sep = 1;
		else if (prev_is_sep)
		{
			prev_is_sep = 0;
			tot++;
		}
		s++;
	}
	return (tot);
}

void	free_progress(char **spliced, size_t alloc_so_far)
{
	size_t	i;

	i = 0;
	while (i < alloc_so_far)
	{
		free(spliced[i]);
		i++;
	}
	free(spliced);
}

size_t	copy_word(char const *s, char c, char **spliced, size_t word_idx)
{
	size_t	word_len;
	size_t	k;

	word_len = 0;
	k = 0;
	while (s[k] && s[k] != c)
	{
		word_len++;
		k++;
	}
	spliced[word_idx] = malloc(word_len + 1);
	if (!spliced[word_idx])
		return (0);
	ft_strlcpy(spliced[word_idx], s, word_len + 1);
	return (k);
}

char	**ft_split(char const *s, char c)
{
	char	**spliced;
	size_t	words_size;
	size_t	word_idx;
	size_t	j;

	if (!s)
		return (NULL);
	words_size = calcuate_words(s, c);
	spliced = ft_calloc(words_size + 1, sizeof(char *));
	if (!spliced)
		return (NULL);
	word_idx = 0;
	j = 0;
	while (word_idx < words_size)
	{
		while (s[j] && s[j] == c)
			j++;
		j += copy_word(s + j, c, spliced, word_idx);
		if (!spliced[word_idx])
			return (free_progress(spliced, word_idx), (NULL));
		word_idx++;
	}
	spliced[word_idx] = NULL;
	return (spliced);
}
