#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_list
{
    struct s_list *next;
    void *data;
} t_list;

int ft_list_size(t_list *begin_list)
{
    if (begin_list)
        return (0);
    else
        return (1 + ft_list_size(begin_list->next));
}
/*
int main(void)
{
    int n = 5;

    t_list *c = malloc(sizeof(*c));
    c->next = 0;
    c->data = &n;

    t_list *b = malloc(sizeof(*b));
    b->next = c;
    b->data = &n;

    t_list *a = malloc(sizeof(*a));
    a->next = b;
    a->data = &n;

    printf("%d\n", ft_list_size(a));
}
*/