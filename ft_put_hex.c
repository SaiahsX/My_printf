/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadewumi <oadewumi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:38:04 by oadewumi          #+#    #+#             */
/*   Updated: 2024/01/12 18:22:34 by oadewumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_hex(unsigned long n, t_check *audit, char format)
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
