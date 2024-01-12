/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadewumi <oadewumi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:31:42 by oadewumi          #+#    #+#             */
/*   Updated: 2024/01/12 16:08:42 by oadewumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_check
{
	int	error;
	int	count;
}				t_check;

int		ft_printf(const char *input, ...);

void	ft_put_hex(unsigned long n, t_check *audit, char format);
void	ft_put_ptr_hex(unsigned long ptr, t_check *audit);
void	ft_put_unsign_fd(unsigned int nb, t_check *audit);
void	ft_putnbr_fd(int nb, t_check *audit);
void	ft_putchar_fd(char c, t_check *audit);
void	ft_putstr_fd(char *s, t_check *audit);


#endif