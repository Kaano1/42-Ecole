/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:59:12 by ayumusak          #+#    #+#             */
/*   Updated: 2023/03/19 16:28:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] == s2[i] && s1[i] != 0 && n - 1 > i)
		i++;
	if ((unsigned char)(s1[i]) - (unsigned char)(s2[i]) < 0)
		return (-1);
	else if ((unsigned char)(s1[i]) - (unsigned char)(s2[i]) > 0)
		return (1);
	else
		return (0);
}
