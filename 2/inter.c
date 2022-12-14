#include <unistd.h>
#include <stdio.h>

int main(int ac, char **av)
{
    int i = 0;
    int ii = 0;
    int k = 0;
    char *s1;
    char *s2;

    if (ac == 3)
    {
        s1 = av[1];
        s2 = av[2];
        while (s1[i])
        {
            ii = 0;
            while (s2[ii])
            {
                if (s1[i] == s2[ii])
                {
                    k = 0;
                    while (s1[i] != s1[k])
                        k++;
                    if (k == i)
                    {
                        k = 0;
                        while (s2[k] != s2[ii])
                            k++;
                        if (k == ii)
                            write(1, &s1[i], 1);
                    }
                }
                ii++;
            }
            i++;
        }
    }
    write(1, "\n", 1);
}