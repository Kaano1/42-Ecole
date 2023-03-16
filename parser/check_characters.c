#include "../include/cub3d.h"

int check_characters(t_data *data)
{
	t_map	**map;
	int		i;
	int		j;
	int		a;

	i = -1;
	/*while (data->map[++i])
	{
		j = -1;
		a = 0;
		map = data->map;
		while (!(map[i][++j]))
		{
			if (!ft_strchr("01NSEW", map[i][j]))
				ft_putstr_fd("Error\nInvalid Character\n", 2);
			else if ((map[i][j] == 'N')|| (map[i][j] == 'W') || \
				(map[i][j] == 'E') || (map[i][j] == 'S'))
				a++;
		}
		 if(a != 1)
				ft_putstr_fd("Error\nMore than one char\n", 2);
	}*/
}
