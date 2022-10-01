/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayumusak <ayumusak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 09:30:13 by ayumusak          #+#    #+#             */
/*   Updated: 2022/01/30 22:52:24 by ayumusak         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		len_s1;
	int		len_s2;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (0);
	len_s1 = (ft_strlen((char *)s1));
	len_s2 = (ft_strlen((char *)s2));
	res = (char *)malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	ft_strlcpy(res, s1, len_s1 + 1);
	ft_strlcpy(&res[len_s1], s2, len_s2 + 1);
	free(s1);
	return (res);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srcsize;
	size_t	j;

	j = 0;
	srcsize = 0;
	if (!dstsize)
		return (ft_strlen(src));
	srcsize = ft_strlen(src);
	if (dstsize != 0)
	{
		while (j < dstsize - 1 && src[j])
		{
			((char *)dst)[j] = ((const char *)src)[j];
			j++;
		}
		dst[j] = '\0';
	}
	return (srcsize);
}
