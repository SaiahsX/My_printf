/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ptr_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadewumi <oadewumi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:25:34 by oadewumi          #+#    #+#             */
/*   Updated: 2024/01/23 13:47:29 by oadewumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	This is a helper function for my ft_printf with the intent to write out 
	a pointer address.
	This helper function is also inttended to write out hexadecimals with a 
	difference of always having '0x' as a prefix.
	Another helper function ft_putstr is utilised to always write out the 
	prefix '0x' before any other thing.
	If the pointer 'ptr' points to 0 or if its a null pointer, we use the 
	another helper function to write '0' after the prefix '0x'.
	Else, we use the helper function, ft_put_hex to write the hexadecimals 
	after the prefix.
	There you go, we have our pointer address addressed.  	*/

#include "ft_printf.h"

void	ft_put_ptr_hex(unsigned long long ptr, t_check *audit)
{
	ft_putstr_fd("0x", audit);
	if (!ptr)
		ft_putchar_fd('0', audit);
	else
		ft_put_hex(ptr, audit, 'x');
}
