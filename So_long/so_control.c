/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_control.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayumusak <ayumusak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 14:22:41 by ayumusak          #+#    #+#             */
/*   Updated: 2022/08/16 18:19:18 by ayumusak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	so_check(t_list *lst)
{
	while (lst->map[lst->row] != 0)
		lst->row++;
	while (lst->map[0][lst->column])
		lst->column++;
	check_col_row(lst);
	check_walls(lst);
	check_other(lst);
	check_new_line(lst);
}

void	check_col_row(t_list *lst)
{
	int	i;

	i = 0;
	while (i < lst->row)
	{
		if (ft_strlen(lst->map[i]) != lst->column)
			so_error("Error\nThere is a problem column\n");
		i++;
	}
}

void	check_walls(t_list *lst)
{
	int	x;
	int	y;

	y = 0;
	while (lst->map[y])
	{
		x = 0;
		while (lst->map[y][x])
		{
			if ((x == 0 || lst->column - 1 == x) && lst->map[y][x] != '1')
				so_error("Error\nThere is a problem in walls, be careful!\n");
			else if ((y == 0 || lst->row - 1 == y) && lst->map[y][x] != '1')
				so_error("Error\nThere is a problem ground or plafond!\n");
			x++;
		}
		y++;
	}
}

void	if_control(t_list *lst, int i, int j)
{
	if (lst->map[j][i] == 'P')
	{
		lst->person_x = i;
		lst->person_y = j;
		lst->c_person++;
	}
	else if (lst->map[j][i] == 'C')
		lst->c_coin++;
	else if (lst->map[j][i] == 'E')
		lst->c_exit++;
	else if (lst->map[j][i] != '1' && lst->map[j][i] != '0' &&
			lst->map[j][i] != '\n')
		so_error("Error\nThere is a unknown character at the map!\n");
}

void	check_other(t_list *lst)
{
	int	i;
	int	j;

	j = -1;
	while (lst->map[++j])
	{
		i = -1;
		while (lst->map[j][++i] != 0)
			if_control(lst, i, j);
	}
	if (lst->c_person != 1)
		so_error("Error\nperson is not equat one\n");
	else if (lst->c_coin <= 0)
		so_error("Error\nyou must add a coin\n");
	else if (lst->c_exit == 0)
		so_error("Error\nexit door has a problem\n");
}
