#include <stdio.h>
#include <unistd.h>

int ft_atoi(const char *str)
{
    int i = 0;
    int nbr = 0;
    int neg = 1;

    if (str[0] == '+' || str[0] == '-')
        i++;
    if (str[0] == '-')
        neg = -1;
    while (str[i] && str[i] >= '0' && str[i] <= '9')
    {
        nbr = nbr * 10 + str[i] - '0';
        i++;
    }
    return (nbr * neg);
}
/*
int main()
{
    int res;
    res = ft_atoi("-42leo");
    printf("%d\n", res);
}
*/