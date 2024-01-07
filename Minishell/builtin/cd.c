/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtorun <mtorun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 02:01:52 by mtorun            #+#    #+#             */
/*   Updated: 2023/02/02 02:01:54 by mtorun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	builtin_cd(char **input)
{
	char	*home;

	if (input[1] != NULL)
	{
		if (chdir(input[1]) != 0)
			perror("minishell ");
	}
	else
	{
		home = getenv("HOME");
		if (home && *home)
			if (chdir(home))
				perror("minishell ");
	}
	if (!is_parent())
		exit (g_ms.exit_code);
}
