/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadewumi <oadewumi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:01:32 by oadewumi          #+#    #+#             */
/*   Updated: 2024/01/23 13:48:46 by oadewumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	This is a heler function for my ft_printf function that handles and writes
out numbers (integers)	*/

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
