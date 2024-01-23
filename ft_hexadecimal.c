/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_Hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadewumi <oadewumi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:38:04 by oadewumi          #+#    #+#             */
/*   Updated: 2024/01/23 18:42:37 by oadewumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	This is a helper function for my ft_printf function.
	This function is intended to handle and wite out hexadecimals denoted
	by the format 'x' and 'X'. 
	A singular helper function is used to handle both cases of 'x' and 'X'.
	This was achieved by declaring an 'int' which is used as a switch.
	This switch is influenced by the argument parameter, 'format' depending 
	on the 'x'	and 'X' format it received. The switch is with a reference to 
	an ascii value that is further utilised in the function.
	The function is somewhat similar to ft_putnbr which is a base 10 in 
	its recurssive approach but	this is in base 16.	*/

#include "ft_printf.h"

void	ft_hexadecimal(unsigned long long n, t_check *audit, char format)
{
	int	fmt;

	fmt = 'a';
	if (format == 'X')
		fmt = 'A';
	if (n >= 16)
	{
		ft_put_hex((n / 16), audit, format);
		n = n % 16;
	}
	if (n < 10)
		ft_putchar_fd(n + '0', audit);
	else
		ft_putchar_fd((n - 10) + fmt, audit);
}
