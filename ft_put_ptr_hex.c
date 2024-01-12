/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ptr_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadewumi <oadewumi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:25:34 by oadewumi          #+#    #+#             */
/*   Updated: 2024/01/12 18:45:20 by oadewumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_put_ptr_hex(unsigned long ptr, t_check *audit)
{
	ft_putstr_fd("0x", audit);
	if (!ptr)
		ft_putchar_fd('0', audit);
		return ;
	ft_put_hex(ptr, audit, 'x');
}
