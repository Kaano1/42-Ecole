/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayumusak <ayumusak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 17:10:08 by ayumusak          #+#    #+#             */
/*   Updated: 2022/08/31 17:10:09 by ayumusak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s_write(char *str, int mod)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(mod, &str[i], 1);
		i++;
	}
}

void	error(char *str)
{
	s_write("Error\n", 2);
	exit (-1);
}
