/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ptr_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadewumi <oadewumi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:25:34 by oadewumi          #+#    #+#             */
/*   Updated: 2024/01/22 18:33:06 by oadewumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_ptr_hex(unsigned long long ptr, t_check *audit)
{
	ft_putstr_fd("0x", audit);
	if (!ptr)
		ft_putchar_fd('0', audit);
	else
		ft_put_hex(ptr, audit, 'x');
}
