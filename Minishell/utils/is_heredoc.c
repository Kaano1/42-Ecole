/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtorun <mtorun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 01:57:06 by mtorun            #+#    #+#             */
/*   Updated: 2023/02/02 01:57:07 by mtorun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	contain_heredoc(t_process *process)
{
	int	i;

	i = 0;
	while (process->redirects[i])
	{
		if (is_operator(process->redirects[i]) == HERE_DOC)
			return (TRUE);
		i++;
	}
	return (FALSE);
}
