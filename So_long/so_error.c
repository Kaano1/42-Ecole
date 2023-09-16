/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayumusak <ayumusak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 14:20:04 by ayumusak          #+#    #+#             */
/*   Updated: 2022/08/16 14:22:04 by ayumusak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	so_error(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	exit (-1);
}

void	malloc_error(int fd, char *str)
{
	close(fd);
	so_error(str);
}
