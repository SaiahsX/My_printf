/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadewumi <oadewumi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:23:42 by oadewumi          #+#    #+#             */
/*   Updated: 2024/01/11 11:02:28 by oadewumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_fd(char c, t_check *audit)
{
	if (audit->error == -1)
		return ;
	if (write (1, &c, 1) < 0)
		audit->error = -1;
	audit->count++;
}
