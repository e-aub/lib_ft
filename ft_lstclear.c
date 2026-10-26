#include "libft.h"

void ft_lstclear(t_list **lst, void (*del)(void*)){
    if(!lst || !del){
        return;
    }

    t_list *tmp;
    while(*lst){
        tmp = (*lst)->next;
        del((*lst)->content);
        free(*lst);
        *lst = tmp;
    }

    *lst = NULL;
}

void del(void * addr){
    free(addr);
}

int	main(void)
{

    t_list *f = ft_lstnew(ft_strdup("hello"));
	t_list *s = ft_lstnew(ft_strdup("hello"));
	// t_list *t = ft_lstnew("3");

	// ft_lstadd_back(&f, s);
	ft_lstadd_back(&f, s);


    ft_lstclear(&f, del);

    printf("%p", f);
}

