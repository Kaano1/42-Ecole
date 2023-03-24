/* ************************************************************************** */
/*																									*/
/*																		 :::		::::::::	*/
/*	get_next_line.h												:+:		:+:	:+:	*/
/*																	+:+ +:+			+:+	 */
/*	By: marvin <marvin@student.42.fr>				 +#+  +:+		+#+		 */
/*																+#+#+#+#+#+	+#+			 */
/*	Created: 2022/02/12 15:41:45 by kkocaaga			#+#	#+#				*/
/*	Updated: 2023/03/15 17:20:43 by marvin			 ###	########.fr		*/
/*																									*/
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

char	*get_next_line(int fd);
char	*ft_get_str(int fd, char *str);

int		t_strchr(char *str, int c);
char	*t_strjoin(char *str, char *temp_str);
char	*ft_get_line(char *str);
char	*ft_get_new_str(char *str);

#endif
