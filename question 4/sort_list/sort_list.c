#include <stdlib.h>

typedef struct s_list t_list;

struct s_list
{
    int     data;
    t_list  *next;
};

t_list *sort_list(t_list *lst, int (*cmp)(int, int))
{
    int swap;
    t_list *tmp;

    tmp = lst;
    while (lst->next != NULL)
    {
        if (((*cmp)(lst->data, lst->next->data)) == 0)
        {
            swap = lst->data;
            lst->data = lst->next->data;
            lst->next->data = swap;
            lst = tmp;
        }
        else
            lst = lst->next;
    }
    lst = tmp;
    return (lst);
}

/*
int ascending(int a, int b)
{
    return (a <= b);
}

int main(void)
{
    t_list *c = malloc(sizeof(t_list));
    c->next = 0;
    c->data = 45;

    t_list *b = malloc(sizeof(t_list));
    b->next = c;
    b->data = 73;

    t_list *a = malloc(sizeof(t_list));
    a->next = b;
    a->data = 108;

    t_list *cur = a;
    while (cur)
    {
        printf("%d, ", cur->data);
        cur = cur->next;
    }
    printf("\n");

    cur = sort_list(a, ascending);

    // cur = a;
    while (cur)
    {
        printf("%d, ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}
*/
