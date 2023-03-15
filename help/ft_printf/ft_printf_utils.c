/* ************************************************************************** */
/*																									*/
/*																		 :::		::::::::	*/
/*	ft_printf_utils.c											:+:		:+:	:+:	*/
/*																	+:+ +:+			+:+	 */
/*	By: kkocaaga <42istanbul.com.tr>					+#+  +:+		+#+		 */
/*																+#+#+#+#+#+	+#+			 */
/*	Created: 2022/03/17 14:41:29 by kkocaaga			#+#	#+#				*/
/*	Updated: 2022/03/17 14:41:31 by kkocaaga			###	########.tr		*/
/*																									*/
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_str(char *s)
{
	int	count;

	count = 0;
	if (!(s))
	{
		count += write(1, "(null)", 6);
		return (count);
	}
	while (*s)
	{
		write(1, s, 1);
		count++;
		s++;
	}
	return (count);
}

int	ft_pointer(long double number, int base, int is_upper)
{
	int	count;

	count = 0;
	count += ft_str("0x");
	count += ft_putnbr(number, base, is_upper);
	return (count);
}

int	ft_putnbr(long double number, int base, int is_upper)
{
	int	count;

	count = 1;
	if (number < 0)
	{
		count++;
		number = -number;
		write(1, "-", 1);
	}
	if (number >= base)
		count += ft_putnbr((unsigned long)number / base, base, is_upper);
	if (is_upper)
		write (1, &UPPER_BASE[(unsigned long)number % base], 1);
	else
		write (1, &LOWER_BASE[(unsigned long)number % base], 1);
	return (count);
}
