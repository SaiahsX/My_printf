/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadewumi <oadewumi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:03:51 by oadewumi          #+#    #+#             */
/*   Updated: 2024/01/12 19:24:56 by oadewumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_format_check(va_list arg_pnt, char format, t_check *audit)
{
	if (format == 'c')
		ft_putchar_fd(va_arg(arg_pnt, int), audit);
	else if (format == '%')
		ft_putchar_fd('%', audit);
	else if (format == 's')
		ft_putstr_fd(va_arg(arg_pnt, char *), audit);
	else if (format == 'd' || format == 'i')
		ft_putnbr_fd(va_arg(arg_pnt, int), audit);
	else if (format == 'u')
		ft_put_unsign_fd(va_arg(arg_pnt, unsigned int), audit);
	else if (format == 'x' || format == 'X')
		ft_put_hex(va_arg(arg_pnt, unsigned long), audit, format);
	else if (format == 'p')
		ft_put_ptr_hex(va_arg(arg_pnt, unsigned long), audit);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg_pnt;
	t_check	audit;

	audit.error = 0;
	audit.count = 0;
	va_start(arg_pnt, format);
	while (*format && audit.error == 0)
	{
		if (*format == '%')
		{
			format++;
			ft_format_check(arg_pnt, *format, &audit);
		}
		else if (*format != '\0')
			ft_putchar_fd(*format, &audit);
		if (*format != '\0')
			format++;
	}
	va_end(arg_pnt);
	if (audit.error < 0)
		return (-1);
	return (audit.count);
}
#include <stdio.h>

#include <limits.h>

int	main(void)
{
	// long x = 2147483649;
	// int y = 1;
	// char *str = "fish";
	int test = 0;
	// int oh = 15 / 16;
	// int oh2 = 14 % 16;
	// printf("ft_printf value = %d\n", ft_printf("The result is: %d\n", x));
	// printf("Printf value = %d\n", 	printf("The result is: %d\n", x));
	// ft_printf("ft_printf checking ft_printf value = %d\n", ft_printf("The result is: %d\n", x));
	// ft_printf("ft_printf checking printf value = %d\n", printf("The result is: %d\n", x));
	// printf("This is the format %%p = %p\n", test);
	// printf("this is 15 / 16 %d\n", oh);
	// printf("this is 15 %% 16 %d\n", oh2);
	ft_printf("This is ft_printf format p: %p\n", test);
	printf("This is printf format p: %p\n", test);
	// return (0);
}
