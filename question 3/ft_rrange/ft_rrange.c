#include <stdlib.h>
#include <stdio.h>

int *ft_rrange(int start, int end)
{
    int *range;
    int n = start > end ? start - end + 1 : end - start + 1;
    int dir = start < end ? 1 : -1;

    range = (int *)malloc(sizeof(int) * n);
    while (n--)
    {
        range[n] = start;
        start += dir;
    }
    return range;
}

/*
int main()
{
    int *tab;
    int i;
    tab = ft_rrange(1, 5);
    while (i < 5)
    {
        printf("%d\n", tab[i]);
        i++;
    }
}
*/