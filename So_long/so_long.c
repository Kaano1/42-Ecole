/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayumusak <ayumusak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 14:19:49 by ayumusak          #+#    #+#             */
/*   Updated: 2022/08/20 15:04:16 by ayumusak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	section(t_list *lst, int i, int j)
{
	if (lst->map[i][j] == '1')
		mlx_put_image_to_window(lst->mlx, lst->win, lst->wall, j * 64, i * 64);
	else if (lst->map[i][j] == '0')
		mlx_put_image_to_window(lst->mlx, lst->win, lst->empty, j * 64, i * 64);
	else if (lst->map[i][j] == 'C')
		mlx_put_image_to_window(lst->mlx, lst->win, lst->coin, j * 64, i * 64);
	else if (lst->map[i][j] == 'P')
		mlx_put_image_to_window(lst->mlx, lst->win, lst->p, j * 64, i * 64);
	else if (lst->map[i][j] == 'E')
		mlx_put_image_to_window(lst->mlx, lst->win, lst->exit, j * 64, i * 64);
}

void	put_map(t_list *list)
{
	int		i;
	int		j;

	i = 0;
	while (list->map[i] != NULL)
	{
		j = 0;
		while (list->map[i][j] != 0)
		{
			section(list, i, j);
			j++;
		}
		i++;
	}
}

void	add_image(t_list *lst)
{
	int	x;

	x = 64;
	lst->coin = mlx_xpm_file_to_image(lst->mlx, "xpm/coin.xpm", &x, &x);
	lst->p_down = mlx_xpm_file_to_image(lst->mlx, "xpm/down.xpm", &x, &x);
	lst->empty = mlx_xpm_file_to_image(lst->mlx, "xpm/empty.xpm", &x, &x);
	lst->exit = mlx_xpm_file_to_image(lst->mlx, "xpm/exit.xpm", &x, &x);
	lst->p_left = mlx_xpm_file_to_image(lst->mlx, "xpm/left.xpm", &x, &x);
	lst->p_right = mlx_xpm_file_to_image(lst->mlx, "xpm/right.xpm", &x, &x);
	lst->p_up = mlx_xpm_file_to_image(lst->mlx, "xpm/up.xpm", &x, &x);
	lst->wall = mlx_xpm_file_to_image(lst->mlx, "xpm/wall.xpm", &x, &x);
	lst->p = lst->p_up;
}

void	zero(t_list *lst)
{
	lst->c_coin = 0;
	lst->c_exit = 0;
	lst->c_person = 0;
	lst->column = 0;
	lst->row = 0;
	lst->person_x = 0;
	lst->person_y = 0;
	lst->p_coin = 0;
	lst->move = 0;
}

int	main(int ac, char **av)
{
	t_list	lst;

	if (ac == 2 && ctr_ber(av[1], ".ber"))
	{
		lst.mlx = mlx_init();
		zero(&lst);
		add_map(&lst, av[1]);
		add_image(&lst);
	lst.win = mlx_new_window(lst.mlx, lst.column * 64, lst.row * 64, "so_long");
		put_map(&lst);
		mlx_hook(lst.win, 2, 1L << 0, &key, &lst);
		mlx_hook(lst.win, 17, 0, &ft_x, &lst);
		mlx_loop(lst.mlx);
	}
	return (0);
}
