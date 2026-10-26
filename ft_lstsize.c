/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayouel-h <ayouel-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 13:05:59 by ayouel-h          #+#    #+#             */
/*   Updated: 2026/10/26 13:09:36 by ayouel-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_lstsize(t_list *lst)
{
	unsigned int	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

// int main(){
//     t_list *f = ft_lstnew("1");
//     t_list *s = ft_lstnew("2");
//     t_list *t = ft_lstnew("3");

//     ft_lstadd_front(&t, s);
//     ft_lstadd_front(&s, f);

//     // while(f){
//     //     printf("%s\n", (char *)f->content);
//     //     f = f->next;
//     // }

//     size_t size = ft_lstsize(f);
//     printf("size: %zu\n", size);

// }