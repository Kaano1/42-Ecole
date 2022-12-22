#include <unistd.h>

int main(int ac, char **av)
{
    int i = 0;
    int start;
    int finish;
    int flag;

    if (ac == 2)
    {
        while (av[1][i])
            i++;
        while (i >= 0)
        {
            while (av[1][i] == '\0' || av[1][i] == ' ' || av[1][i] == '\t')
                i--;
            finish = i;
            while (av[1][i] && av[1][i] != ' ' && av[1][i] != '\t')
                i--;
            start = i + 1;
            flag = start;
            while (start <= finish)
            {
                write(1, &av[1][start], 1);
                start++;
            }
            if (flag != 0)
                write(1, " ", 1);
        }
    }
    write(1, "\n", 1);
}
