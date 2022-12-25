#include "ft_list.h"

void ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
    while (begin_list)
    {
        (*f)(curr->data);
        begin_list = begin_list->next;
    }
}
