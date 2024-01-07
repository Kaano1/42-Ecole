/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtorun <mtorun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 01:59:09 by mtorun            #+#    #+#             */
/*   Updated: 2023/02/02 01:59:10 by mtorun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_count_digit(long n)
{
	long	i;

	i = 0;
	if (n == 0)
		i = 1;
	else if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*value;
	size_t	count;
	long	number;

	number = n;
	count = ft_count_digit(n);
	value = (char *)malloc(sizeof(char) * (count + 1));
	if (!value)
		return (NULL);
	value[count--] = 0;
	if (number == 0)
		value[0] = '0';
	if (number < 0)
	{
		value[0] = '-';
		number = -number;
	}
	while (number > 0)
	{
		value[count--] = (number % 10) + 48;
		number /= 10;
	}
	return (value);
}
