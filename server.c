/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayumusak <ayumusak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 00:37:01 by ayumusak          #+#    #+#             */
/*   Updated: 2022/03/01 17:28:59 by ayumusak         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void	past(int num)
{
	if (num > 10)
		past(num / 10);
	write(1, &"0123456789"[num % 10], 1);
}

void	ft_bit(int c)
{
	static int	i = 7;
	static char	bit = 0;

	bit += c << i;
	if (i == 0)
	{
		i = 7;
		write(1, &bit, 1);
		bit = 0;
	}
	else
		i--;
}

void	ft_read(int fd)
{
	if (fd == SIGUSR1)
		ft_bit(1);
	else if (fd == SIGUSR2)
		ft_bit(0);
}

int	main(void)
{
	past(getpid());
	signal(SIGUSR1, ft_read);
	signal(SIGUSR2, ft_read);
	while (1)
		pause();
}
