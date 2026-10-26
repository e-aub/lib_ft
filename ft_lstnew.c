/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayouel-h <ayouel-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 12:39:07 by ayouel-h          #+#    #+#             */
/*   Updated: 2026/10/26 12:39:09 by ayouel-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
	{
		return (NULL);
	}
	node->next = NULL;
	node->content = content;
	return (node);
}

// int main(){
//     t_list *node = ft_lstnew("hello world");

//     printf("%s\n", (char *)node->content);
//     printf("%p\n", (char *)node->next);

// }