/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayumusak <ayumusak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 00:05:47 by  mcakay           #+#    #+#             */
/*   Updated: 2022/10/19 01:38:48 by ayumusak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_join_threads(t_philo *philo, char **argv)
{
	int	i;

	i = 0;
	while (i < ft_atol(argv[1]))
	{
		pthread_create(&philo[i].thread, NULL, &ft_dinner, &philo[i]);
		i++;
		usleep(1000);
	}
	while (*philo->is_dead != 1)
		ft_check_death(philo);
}
