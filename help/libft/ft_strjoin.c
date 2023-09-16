/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayumusak <ayumusak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 19:03:14 by ayumusak          #+#    #+#             */
/*   Updated: 2023/05/03 19:03:16 by ayumusak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*len;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	len = malloc(sizeof(char) * (s1_len + ft_strlen(s2) + 1));
	if (!len)
		return (0);
	ft_strlcpy(len, s1, s1_len + 1);
	ft_strlcpy(&len[s1_len], s2, s2_len + 1);
	return (len);
}
