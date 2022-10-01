/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayumusak <ayumusak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 14:19:57 by ayumusak          #+#    #+#             */
/*   Updated: 2022/08/20 16:12:59 by ayumusak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <string.h>
# include "min/mlx.h"
# include <fcntl.h>
# include <unistd.h>

typedef struct s_list
{
	void	*mlx;
	void	*win;
	char	**map;
	char	*bf;

	int		person_x;
	int		person_y;

	void	*p_left;
	void	*p_right;
	void	*p_up;
	void	*p_down;
	void	*wall;
	void	*empty;
	void	*exit;
	void	*coin;
	void	*p;

	int		height;
	int		width;

	int		p_coin;
	int		c_coin;
	int		c_person;
	int		c_exit;
	int		row;
	int		column;

	int		move;
}	t_list;

char	**ft_split(char *s, char c);
char	*get_long(char *map, int len, t_list *lst);
int		ft_len(char *map);
void	add_map(t_list *lst, char *str);
int		key(int keycode, t_list *lst);
void	put_map(t_list *list);
void	so_error(char *str);
void	so_control(t_list *lst);
void	so_free_exit(t_list *lst);
int		ft_strlen(char *str);
void	so_check(t_list *lst);
void	check_new_line(t_list *lst);
void	check_col_row(t_list *lst);
void	check_other(t_list *lst);
void	check_walls(t_list *lst);
void	malloc_error(int fd, char *str);
int		ft_x(t_list *lst);
void	*ft_calloc(size_t x, size_t size);
void	ft_move(int num);
int		ctr_ber(char *str, char *s);
#endif