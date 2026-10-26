/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayouel-h <ayouel-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 13:18:01 by ayouel-h          #+#    #+#             */
/*   Updated: 2026/10/26 13:18:01 by ayouel-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (!lst->next)
		{
			return (lst);
		}
		lst = lst->next;
	}
	return (NULL);
}

// int	main(void)
// {
// 	// t_list *f = ft_lstnew("1");
// 	// t_list *s = ft_lstnew("2");
// 	// t_list *t = ft_lstnew("3");

// 	// ft_lstadd_front(&t, s);
// 	// ft_lstadd_front(&s, f);

// 	// while(f){
// 	//     printf("%s\n", (char *)f->content);
// 	//     f = f->next;
// 	// }

// 	t_list *last = ft_lstlast(NULL);
// 	printf("%s\n", (char *)last->content);
// }