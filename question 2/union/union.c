#include <unistd.h>

int main(int ac, char **av)
{
    if (ac == 3)
    {
        int i = 0;
        int alpha[26] = {0};
        while (av[1][i])
        {
            if (alpha[av[1][i] - 'a'] == 0)
            {
                write(1, &av[1][i], 1);
                alpha[av[1][i] - 'a'] = 1;
            }
            i++;
        }
        i = 0;
        while (av[2][i])
        {
            if (alpha[av[2][i] - 'a'] == 0)
            {
                write(1, &av[2][i], 1);
                alpha[av[2][i] - 'a'] = 1;
            }
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}