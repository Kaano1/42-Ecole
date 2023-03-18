#include "../../include/cub3d.h"

int	difChar(char **sp_pix)
{
	int	i;
	int	j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (sp_pix[i][j])
		{
			if (!ft_isdigit(sp_pix[i][j]) && !is_space(sp_pix[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

t_pixel	add_Pixel(char *line, t_map *data, int sta)
{
	t_pixel	pix;
	int		i;
	char	**sp_pix;

	i = 0;
	pix.sta = sta;
	sp_pix = ft_split(line, ',');
	while (sp_pix[i])
		i++;
	if (i == 3 && !difChar(sp_pix) && sta == 0)
	{
		pix.r = ft_atoi(sp_pix[0]);
		pix.g = ft_atoi(sp_pix[1]);
		pix.b = ft_atoi(sp_pix[2]);
		pix.sta++;
	}
	else
	{
		free(line);
		freeArray(sp_pix);
		clear_map_exit(data, ERROR_RGB);
	}
	if ((!(pix.r <= 255 && pix.r >= 0)) || (!(pix.g <= 255 && pix.g >= 0)) 
		|| (!(pix.b <= 255 && pix.b >= 0)))
	{
		free(line);
		clear_map_exit(data, ERROR_RGB);
	}
	freeArray(sp_pix);
	return (pix);
}
