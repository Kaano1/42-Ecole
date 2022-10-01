/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayumusak <ayumusak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 14:20:10 by ayumusak          #+#    #+#             */
/*   Updated: 2022/08/17 17:37:48 by ayumusak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	if_word_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0' && s[len] != c)
		len++;
	return (len);
}

size_t	len_word(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*s != '\0')
	{
		if (*s != c && (s[1] == '\0' || s[1] == c))
			len++;
		s++;
	}
	return (len);
}

char	**ft_split(char *s, char c)
{
	char	**res;
	size_t	index;
	size_t	two_index;
	size_t	word_len;

	if (!s)
		return (NULL);
	word_len = len_word(s, c);
	res = ft_calloc(word_len + 1, sizeof(char *));
	if (res == NULL)
		return (NULL);
	index = 0;
	while (index < word_len)
	{
		while (*s == c && *s != '\0')
			s++;
		res[index] = ft_calloc(if_word_len(s, c), sizeof(char));
		two_index = 0;
		while (*s != c && *s != '\0')
			res[index][two_index++] = *s++;
		res[index][two_index] = '\0';
		index++;
	}
	res[index] = NULL;
	return (res);
}

char	*get_long(char *map, int len, t_list *lst)
{
	int		fd;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		so_error("Error\nFile didn't find!");
	lst->bf = ft_calloc(len + 1, sizeof(char));
	if (!lst->bf)
		malloc_error(fd, "Error\n There is a problem in malloc[0]");
	read(fd, lst->bf, len);
	lst->bf[len] = 0;
	close (fd);
	return (lst->bf);
}

void	add_map(t_list *lst, char *str)
{
	lst->map = ft_split(get_long(str, ft_len(str), lst), '\n');
	if (!lst->map)
		so_error("Error\nDivision error.");
	so_check(lst);
}
