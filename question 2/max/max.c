#include <stdio.h>

int max(int *tab, unsigned int len)
{
    int i = 0;
    int res = tab[i];

    while (i < len)
    {
        if (res < tab[i])
            res = tab[i];
        i++;
    }
    return (res);
}
/*
int main()
{
    int tab[] = {-42, 4000000, -5, -20, 2, -200, 99};
    printf("max : %d\n", max(tab, 7));
}
*/
