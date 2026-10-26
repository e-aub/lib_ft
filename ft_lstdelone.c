/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayouel-h <ayouel-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 16:02:23 by ayouel-h          #+#    #+#             */
/*   Updated: 2026/10/26 16:02:23 by ayouel-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
	{
		return ;
	}
	del(lst->content);
	free(lst);
}

// int	main(void)
// {

//     t_list *f = ft_lstnew(ft_strdup("hello"));
//     ;
// 	t_list *s = ft_lstnew("2");
// 	// t_list *t = ft_lstnew("3");

// 	// ft_lstadd_back(&f, s);
// 	ft_lstadd_back(&f, s);

//     ft_lstdelone(f, del);

//     // while(f){
// 	// 	printf("%s\n", (char *)f->content);
// 	// 	f = f->next;
// 	// }
// }