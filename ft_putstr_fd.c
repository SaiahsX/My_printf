/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadewumi <oadewumi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:02:57 by oadewumi          #+#    #+#             */
/*   Updated: 2024/01/09 16:56:30 by oadewumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_fd(char *s, t_check *audit)
{
	if (!s)
	{
		ft_putstr_fd("(null)", audit);
	}
	while (*s)
	{
		ft_putchar_fd(*s, audit);
		s++;
	}
}