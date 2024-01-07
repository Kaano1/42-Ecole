/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtorun <mtorun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:52:04 by mtorun            #+#    #+#             */
/*   Updated: 2023/02/01 17:52:04 by mtorun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	pipe_space_check(int len, char *str)
{
	int	i;

	i = 0;
	while (str[i] == SPACE)
		i++;
	if (str[i] == '|')
		return (-1);
	while (str[len] == SPACE)
		len--;
	str = 0;
	return (len);
}

int	ft_pipecheck(char *str)
{
	int		len;
	int		i;
	char	c;

	i = 0;
	g_ms.process_count = 0;
	len = pipe_space_check(ft_strlen(str) - 1, str);
	if (len == -1 || str[len] == '|')
	{
		token_err(PIPE);
		return (FALSE);
	}
	while (str[i])
	{
		if (str[i] != SPACE && str[i] != TAB)
			c = str[i];
		i++;
		if (c == '|' && str[i] == '|')
		{
			while (len-- > i - 1)
				str[len] = 0;
		}
	}
	return (TRUE);
}
