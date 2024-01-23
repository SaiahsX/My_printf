/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsign_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadewumi <oadewumi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:31:16 by oadewumi          #+#    #+#             */
/*   Updated: 2024/01/23 21:02:44 by oadewumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	This is a helper function for my ft_printf function that handles and writes
	strings.	*/

#include "ft_printf.h"

void	ft_put_unsign_fd(unsigned int nb, t_check *audit)
{
	if (nb < 10)
	{
		ft_putchar_fd((nb + '0'), audit);
	}
	if (nb >= 10)
	{
		ft_put_unsign_fd((nb / 10), audit);
		nb = (nb % 10) + '0';
		ft_putchar_fd(nb, audit);
	}
}
