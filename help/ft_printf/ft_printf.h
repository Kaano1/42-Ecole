/* ************************************************************************** */
/*																									*/
/*																		 :::		::::::::	*/
/*	ft_printf.h													:+:		:+:	:+:	*/
/*																	+:+ +:+			+:+	 */
/*	By: kkocaaga <42istanbul.com.tr>					+#+  +:+		+#+		 */
/*																+#+#+#+#+#+	+#+			 */
/*	Created: 2022/03/17 14:42:31 by kkocaaga			#+#	#+#				*/
/*	Updated: 2022/03/17 14:42:33 by kkocaaga			###	########.tr		*/
/*																									*/
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include "../libft/libft.h"

# ifndef LOWER_BASE
#  define LOWER_BASE "0123456789abcdef"
# endif

# ifndef UPPER_BASE
#  define UPPER_BASE "0123456789ABCDEF"
# endif

int	ft_putnbr(long double number, int base, int is_upper);
int	ft_putchar(int c);
int	ft_str(char *s);
int	ft_pointer(long double number, int base, int is_upper);

#endif
