#include "libft.h"

void ft_lstiter(t_list *lst, void (*f)(void *)){
    while(lst){
        f(lst->content);
        lst = lst->next;
    }
}

void f(void *content){
    char *c_c = (char *) content;

    while(*c_c){
        *c_c = *c_c - 32;
        c_c++;
    }
}

void print(void *content){
    printf("%s\n", (char *) content);
}

int main(){
    t_list *lst = ft_lstnew(ft_strdup("hello"));
    t_list *lst1 = ft_lstnew(ft_strdup("world"));


    ft_lstadd_back(&lst, lst1);

    ft_lstiter(lst, f);

    ft_lstiter(lst, print);

}