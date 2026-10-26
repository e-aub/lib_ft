/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayouel-h <ayouel-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 15:47:13 by ayouel-h          #+#    #+#             */
/*   Updated: 2026/10/26 15:47:14 by ayouel-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
	{
		return ;
	}
	last = ft_lstlast(*lst);
	if (!last)
	{
		*lst = new;
		return ;
	}
	last->next = new;
}

// int	main(void)
// {
// 	t_list *f = NULL;
// 	t_list *s = ft_lstnew("2");
// 	// t_list *t = ft_lstnew("3");

// 	// ft_lstadd_back(&f, s);
// 	ft_lstadd_back(&f, s);

//     while(f){
// 		 printf("%s\n", (char *)f->content);
// 		 f = f->next;
// 	}
// }