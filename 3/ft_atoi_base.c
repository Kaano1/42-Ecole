#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int ft_check(char *str, char c)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == c)
            return i;
        i++;
    }
    return 0;
}

int ft_atoi_base(const char *str, int str_base)
{
    char *s = "0123456789abcdef";
    char *s1 = "0123456789ABCDEF";
    int i;
    int c = 0;
    i = 0;

    while (str[i])
    {
        c *= str_base;
        if (str[i] >= 'a' && str[i] <= 'f')
            c += ft_check(s, str[i]);
        if (str[i] >= 'A' && str[i] <= 'F')
            c += ft_check(s1, str[i]);
        if (str[i] >= '0' && str[i] <= '9')
            c += ft_check(s, str[i]);
        i++;
    }

    return c;
}
/*
int main()
{
    printf("%d", ft_atoi_base("f", 16));
}
*/