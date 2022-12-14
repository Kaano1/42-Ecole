#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int ft_atoi(char *str)
{
    int n = 0;
    while (*str != '\0')
        n = n * 10 + *str++ - '0';
    return (n);
}

void ft_hex(int n)
{
    char i[] = "0123456789abcdef";

    if (n >= 16)
        ft_hex(n / 16);
    write(1, &i[n % 16], 1);
}
/*
int main(int argc, char **argv)
{
    if (argc == 2)
        ft_hex(ft_atoi(argv[1]));
    write(1, "\n", 1);
}
*/