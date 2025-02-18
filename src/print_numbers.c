/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwei <fwei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:42:37 by fwei              #+#    #+#             */
/*   Updated: 2024/12/18 23:06:47 by fwei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	print_decimal(t_flags flags, va_list *args, int *char_count)
{
	int	d;
	int	len;
	int	num_len;

	d = va_arg(*args, int);
	num_len = get_numlen(ft_ads(d), 10);
	len = num_len;
	if (flags.precision > num_len
		|| (flags.dot && flags.precision == 0 && d == 0))
		len = flags.precision;
	if (d < 0 || flags.plus)
		len += 1;
	if (!flags.left && !flags.zero)
		print_padding(flags.width, len, ' ', char_count);
	print_sign(d, flags, char_count);
	if (flags.zero)
		print_padding(flags.width, len, '0', char_count);
	print_num_padding(flags.precision, num_len, char_count);
	if (!(d == 0 && flags.dot && flags.precision == 0))
		put_numbase(ft_ads(d), "0123456789", 10, char_count);
	if (flags.left)
		print_padding(flags.width, len, ' ', char_count);
}

void	print_unsigned(t_flags flags, va_list *args, int *char_count)
{
	unsigned int	u;
	int				len;
	int				num_len;

	u = va_arg(*args, unsigned int);
	num_len = get_numlen(u, 10);
	len = num_len;
	if (flags.precision > num_len
		|| (flags.dot && flags.precision == 0 && u == 0))
		len = flags.precision;
	if (!flags.left && !flags.zero)
		print_padding(flags.width, len, ' ', char_count);
	if (flags.zero)
		print_padding(flags.width, len, '0', char_count);
	print_num_padding(flags.precision, num_len, char_count);
	if (!(u == 0 && flags.dot && flags.precision == 0))
		put_numbase(u, "0123456789", 10, char_count);
	if (flags.left)
		print_padding(flags.width, len, ' ', char_count);
}

void	print_hex(t_flags flags, va_list *args, int *char_count, char *base)
{
	unsigned int	x;
	int				len;
	int				num_len;

	x = va_arg(*args, unsigned int);
	num_len = get_numlen(x, 16);
	len = num_len;
	if (flags.precision > num_len
		|| (flags.dot && flags.precision == 0 && x == 0))
		len = flags.precision;
	if (flags.hash)
		len += 2;
	if (!flags.left && !flags.zero)
		print_padding(flags.width, len, ' ', char_count);
	if (flags.type == 'x')
		print_prefix(x, flags, "0x", char_count);
	else if (flags.type == 'X')
		print_prefix(x, flags, "0X", char_count);
	if (flags.zero)
		print_padding(flags.width, len, '0', char_count);
	print_num_padding(flags.precision, num_len, char_count);
	if (!(x == 0 && flags.dot && flags.precision == 0))
		put_numbase(x, base, 16, char_count);
	if (flags.left)
		print_padding(flags.width, len, ' ', char_count);
}
