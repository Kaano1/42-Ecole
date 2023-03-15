#include "cub3d.h"

t_map design_map(char *filename)
{
	t_map a;
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		 ft_putstr_fd("Error\nFolder Error\n", 2);
		exit(1);
	}
	line = get_next_line(fd);
	return (a);
}

int check_characters(t_data *data)
{
	int		i;
	int		j;
	int	 a;

	i = -1;
	/*
	while (++i < data->map[i])
	{
		j = -1;
		 a = 0;
		while (map[i][++j])
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

