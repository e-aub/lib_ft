/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayouel-h <ayouel-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 12:57:38 by ayouel-h          #+#    #+#             */
/*   Updated: 2026/10/26 12:57:38 by ayouel-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
	{
		return ;
	}
	new->next = *lst;
	*lst = new;
}

// int main(){
//     t_list *lst = ft_lstnew("world");
//     t_list *new = ft_lstnew("hello");

//     ft_lstadd_front(&lst, new);

//     while(lst){
//         printf("%s\n", (char *)lst->content);
//         lst = lst->next;
//     }

// }