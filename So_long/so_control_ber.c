/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_control_ber.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayumusak <ayumusak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 15:00:07 by ayumusak          #+#    #+#             */
/*   Updated: 2022/08/20 15:03:47 by ayumusak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ctr_ber(char *str, char *s)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i] == s[j])
		{
			if (str[i + 1] == 0 && s[j + 1] == 0)
				return (1);
			i++;
			j++;
		}
		i++;
	}
	so_error("Error\nextension problem\n");
	return (0);
}
