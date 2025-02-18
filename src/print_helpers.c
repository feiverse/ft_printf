/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwei <fwei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:09:41 by fwei              #+#    #+#             */
/*   Updated: 2024/12/18 23:06:28 by fwei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	print_padding(int width, int len, char pad_char, int *char_count)
{
	if (width > len)
		*char_count += put_nchars(width - len, pad_char);
}

void	print_sign(int value, t_flags flags, int *char_count)
{
	if (value < 0)
		*char_count += write(1, "-", 1);
	else if (flags.plus)
		*char_count += write(1, "+", 1);
	else if (flags.space)
		*char_count += write(1, " ", 1);
}

void	print_prefix(unsigned int v, t_flags flags, char *p, int *char_count)
{
	if (v != 0 && flags.hash)
		*char_count += write(1, p, 2);
}

void	print_num_padding(int precision, int num_len, int *char_count)
{
	if (precision > num_len)
		*char_count += put_nchars(precision - num_len, '0');
}
