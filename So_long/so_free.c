/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayumusak <ayumusak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 14:22:31 by ayumusak          #+#    #+#             */
/*   Updated: 2022/08/16 17:49:57 by ayumusak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_image(t_list *lst)
{
	mlx_destroy_image(lst->mlx, lst->exit);
	mlx_destroy_image(lst->mlx, lst->coin);
	mlx_destroy_image(lst->mlx, lst->p_up);
	mlx_destroy_image(lst->mlx, lst->p_down);
	mlx_destroy_image(lst->mlx, lst->p_left);
	mlx_destroy_image(lst->mlx, lst->p_right);
	mlx_destroy_image(lst->mlx, lst->wall);
	mlx_destroy_image(lst->mlx, lst->empty);
}

void	so_free(t_list *lst)
{
	int	i;

	i = -1;
	while (lst->map[++i])
		free(lst->map[i]);
	free(lst->map);
}

int	ft_x(t_list *lst)
{
	so_free_exit(lst);
	return (0);
}

void	so_free_exit(t_list *lst)
{
	so_free(lst);
	free_image(lst);
	mlx_destroy_window(lst->mlx, lst->win);
	exit (0);
}
