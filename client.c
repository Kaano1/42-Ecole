/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 00:37:01 by ayumusak          #+#    #+#             */
/*   Updated: 2023/01/12 16:47:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void	ft_char(char sg, int IP)
{
	int	j;
	int	i;
	int	num;

	i = 0;
	j = sg;
	num = 128;
	while (i <= 7)
	{
		if (j >= num && num > 0)
		{
			j = j - num;
			kill(IP, SIGUSR1);
		}
		else
		{
			kill(IP, SIGUSR2);
		}
		i++;
		num /= 2;
		usleep(100);
	}
}

int	ft_atoi(char *str)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (str[i] <= '9' && str[i] >= '0')
	{
		num = (str[i] - '0') + (num * 10);
		i++;
	}
	return (num);
}

int	main(int ac, char **av)
{
	char	*str;
	char	*str2;
	int		ip;
	int		i;

	if (ac != 3)
	{
		write(1, "fuck off", 9);
		return (0);
	}
	str = &*av[1];
	str2 = &*av[2];
	i = 0;
	ip = ft_atoi(str);
	ft_char('\n', ip);
	while (str2[i])
	{
		ft_char(str2[i], ip);
		i++;
	}
}
