/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadewumi <oadewumi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:02:57 by oadewumi          #+#    #+#             */
/*   Updated: 2024/01/22 18:08:45 by oadewumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

		/* if (write(1, "(null)", 6) == -1)
			audit->error = -1;
		else
			audit->count += 6;
		return ; */

#include "ft_printf.h"

void	ft_putstr_fd(char *s, t_check *audit)
{
	if (!s)
	{
		ft_putstr_fd("(null)", audit);
		return ;
	}
	while (*s)
	{
		ft_putchar_fd(*s, audit);
		s++;
	}
}
