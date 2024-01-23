/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadewumi <oadewumi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:02:57 by oadewumi          #+#    #+#             */
/*   Updated: 2024/01/23 20:47:47 by oadewumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	This a helper function for my ft_printf with the intention of writing
	out a string of characters to the standard output.
	
	This function receives a string and struct t_check audit as arguments.
	
	Edge cases of an empty string is first checked to which a "(null)" is passed
	as a new parameter to be written should this be the case.
	
	As an alternative to recursively calling the ft_putstr_fd, the following 
	method can be used for similar outcome.
	
		if (write(1, "(null)", 6) == -1)
			audit->error = -1;
		else
			audit->count += 6;
		return ;
	
	Otherwise, each character of the string is written in the normal way with
	the help of ft_putchar.	*/

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
