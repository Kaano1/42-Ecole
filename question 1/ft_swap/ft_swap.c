#include <unistd.h>

void    ft_swap(int *a, int *b)
{
    int dll;

    dll = *a;
    *a = *b;
    *b = dll;
}