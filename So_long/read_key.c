/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayumusak <ayumusak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 14:20:06 by ayumusak          #+#    #+#             */
/*   Updated: 2022/08/20 16:15:16 by ayumusak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	write_num(int num)
{
	if (num >= 10)
		write_num(num / 10);
	write (1, &"0123456789"[num % 10], 1);
}

void	ft_move(int num)
{
	write_num(num);
	write(1, "\n", 1);
}

int	move(t_list *lst, int want_x, int want_y)
{
	if (lst->map[want_y][want_x] == '1')
		return (0);
	else if (lst->map[want_y][want_x] == 'C')
		lst->p_coin++;
	else if (lst->map[want_y][want_x] == 'E' && lst->c_coin == lst->p_coin)
	{
		lst->move++;
		ft_move(lst->move);
		so_free_exit(lst);
	}
	else if (lst->map[want_y][want_x] == 'E')
		return (0);
	lst->map[lst->person_y][lst->person_x] = '0';
	lst->person_x = want_x;
	lst->person_y = want_y;
	lst->map[lst->person_y][lst->person_x] = 'P';
	lst->move++;
	ft_move(lst->move);
	return (1);
}

int	key(int code, t_list *lst)
{
	mlx_clear_window(lst->mlx, lst->win);
	if (code == 13 || code == 126)
	{
		lst->p = lst->p_up;
		move(lst, lst->person_x, lst->person_y - 1);
	}
	else if (code == 0 || code == 123)
	{
		lst->p = lst->p_left;
		move(lst, lst->person_x - 1, lst->person_y);
	}
	else if (code == 1 || code == 125)
	{
		lst->p = lst->p_down;
		move(lst, lst->person_x, lst->person_y + 1);
	}
	else if (code == 2 || code == 124)
	{
		lst->p = lst->p_right;
		move(lst, lst->person_x + 1, lst->person_y);
	}
	else if (code == 53)
		so_free_exit(lst);
	put_map(lst);
	return (0);
}
