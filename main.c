#include "cub3d.h"

int main(int ac, char **av)
{
    t_data data;
    if(ac == 2 && !ft_strncmp(&av[1][ft_strlen(av[1]) - 4], ".cub", 5))
    {
        
    }
    else
        ft_putstr_fd("Error\nArgument Error\n", 2);
    
}