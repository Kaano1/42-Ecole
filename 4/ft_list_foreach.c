#include <stdlib.h>

typedef struct s_list
{
    struct s_list *next;
    void *data;
} t_list;

void ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
    t_list *curr;

    curr = begin_list;
    while (curr)
    {
        (*f)(curr->data);
        curr = curr->next;
    }
}
