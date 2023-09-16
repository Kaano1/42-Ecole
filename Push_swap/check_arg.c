/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayumusak <ayumusak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:10:25 by ayumusak          #+#    #+#             */
/*   Updated: 2022/09/09 11:08:31 by ayumusak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	arg_control(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] != ' ')
			return (1);
		i++;
	}
	error("Error\n");
	return (0);
}

void	check_arg(char *str)
{
	int	i;

	i = 0;
	arg_control(str);
	while (str[i] != 0)
	{
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == ' ')
			i++;
		else if ((str[i] == '+' || str[i] == '-')
			&& str[i + 1] >= '0' && str[i + 1] <= '9')
				i++;
		else
			error("Error\n");
	}
}
