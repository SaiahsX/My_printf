/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadewumi <oadewumi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:01:32 by oadewumi          #+#    #+#             */
/*   Updated: 2024/01/23 21:03:56 by oadewumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	This is a helper function for my *ft_printf* function that handles and 
	writes trings.

	This function receives an integer and the struct t_check audit as arguments.

	Since strings are to be written from integers, we need to handle the 
	extreme cases of INT MIN. This is done explicitly by looking out for 
	**-2147483648** and using our helper function *ft_putstr_fd* to write 
	that out.

	If the string is greater than INT MIN; first we write out the 
	negative sign '-' with helper function *ft_putchar_fd*, then we proceed to 
	convert the integer to positive, then followed by checking if the integer
	is less than 10. We use helper function *ft_putchar_fd* to perform this 
	while passing 'nd' added to ascii value for conversion into a string.

	If not less we perform the recurssion to split the integer
	and write each value as a string character to the standard output.	*/

#include "ft_printf.h"

void	ft_putnbr_fd(int nb, t_check *audit)
{
	if (nb == -2147483648)
	{
		ft_putstr_fd("-2147483648", audit);
		return ;
	}
	if (nb < 0)
	{
		ft_putchar_fd(('-'), audit);
		nb *= -1;
	}
	if (nb < 10)
	{
		ft_putchar_fd((nb + '0'), audit);
	}
	if (nb >= 10)
	{
		ft_putnbr_fd((nb / 10), audit);
		nb = (nb % 10) + '0';
		ft_putchar_fd(nb, audit);
	}
}
