/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwei <fwei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 21:07:16 by fwei              #+#    #+#             */
/*   Updated: 2024/12/18 18:22:36 by fwei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	parse_format_flags(t_flags *flags, const char *fmt)
{
	while (*fmt && ft_strchr("#-+0 ", *fmt))
	{
		flags->hash |= (*fmt == '#');
		flags->left |= (*fmt == '-');
		flags->plus |= (*fmt == '+');
		flags->zero |= (*fmt == '0');
		flags->space |= (*fmt == ' ');
		fmt++;
	}
	if (*fmt >= '1' && *fmt <= '9')
		flags->width = ft_atoi(fmt);
	while (*fmt >= '0' && *fmt <= '9')
		fmt++;
	if (*fmt == '.')
	{
		flags->dot = 1;
		flags->precision = ft_atoi(++fmt);
		while (*fmt >= '0' && *fmt <= '9')
			fmt++;
	}
	if (*fmt && ft_strchr("cspdiuxX%", *fmt))
		flags->type = *fmt;
}

void	initialize_flags(t_flags *flags)
{
	*flags = (t_flags){0};
}

void	adjust_flags(t_flags *flags)
{
	if (flags->left)
		flags->zero = 0;
	if (flags->plus)
		flags->space = 0;
	if (flags->dot)
		flags->zero = 0;
}

void	process_format(const char *fmt, va_list *args, int *char_count)
{
	t_flags	flags;

	initialize_flags(&flags);
	parse_format_flags(&flags, fmt);
	adjust_flags(&flags);
	if (flags.type == 'c')
		print_char(flags, args, char_count);
	else if (flags.type == 's')
		print_string(flags, args, char_count);
	else if (flags.type == 'p')
		print_pointer(flags, args, char_count);
	else if (flags.type == 'd' || flags.type == 'i')
		print_decimal(flags, args, char_count);
	else if (flags.type == 'u')
		print_unsigned(flags, args, char_count);
	else if (flags.type == 'x')
		print_hex(flags, args, char_count, "0123456789abcdef");
	else if (flags.type == 'X')
		print_hex(flags, args, char_count, "0123456789ABCDEF");
	else if (flags.type == '%')
		*char_count += write(1, "%", 1);
}
