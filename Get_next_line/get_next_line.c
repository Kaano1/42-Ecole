/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayumusak <ayumusak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:17:49 by ayumusak          #+#    #+#             */
/*   Updated: 2022/01/30 22:12:15 by ayumusak         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	new_line(char const *get, int control)
{
	int	i;

	i = 0;
	if (!get)
		return (0);
	while (get[i])
	{
		if (get[i] == '\n')
			return (i);
		i++;
	}
	if (get[i] == 0 && control == 1)
		return (i);
	return (0);
}

char	*after_line_osman(char *get)
{
	char	*catch;
	int		start;
	int		i;

	start = new_line(get, 1);
	if (!get[start])
	{
		free(get);
		return (NULL);
	}
	catch = malloc(sizeof(char) * (ft_strlen(get) - start + 1));
	if (!catch)
		return (0);
	i = 0;
	start++;
	while (get[start] != 0)
		catch[i++] = get[start++];
	catch[i] = 0;
	free(get);
	return (catch);
}

char	*ft_read(int fd, char *get)
{
	int		character;
	char	*catch;

	catch = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!catch)
		return (0);
	character = 20;
	while (character != 0 && !new_line(get, 0))
	{
		character = read(fd, catch, BUFFER_SIZE);
		if (character == -1)
		{
			free(catch);
			return (NULL);
		}
		catch[character] = 0;
		get = ft_strjoin(get, catch);
	}
	free(catch);
	return (get);
}

char	*ft_getline(char *get)
{
	char	*line;
	int		new;

	if (!get[0])
		return (0);
	line = malloc(sizeof(char) *(new_line(get, 1) + 2));
	if (!line)
		return (0);
	new = -1;
	while (get[++new] && get[new] != '\n')
		line[new] = get[new];
	if (get[new] == '\n')
	{
		line[new] = get[new];
		new++;
	}
	line[new] = 0;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*get;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	get = ft_read(fd, get);
	if (!get)
		return (0);
	line = ft_getline(get);
	get = after_line_osman(get);
	return (line);
}

/*
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int	fd;
	fd = open("deneme.txt", O_RDONLY);
	printf("1.%s\n", get_next_line(fd));
	printf("2.%s\n", get_next_line(fd));
	printf("3.%s\n", get_next_line(fd));
	return (0);
}*/
