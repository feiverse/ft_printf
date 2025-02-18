/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_basic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwei <fwei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 19:22:30 by fwei              #+#    #+#             */
/*   Updated: 2024/12/18 23:06:19 by fwei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	print_char(t_flags flags, va_list *args, int *char_count)
{
	int	c;
	int	len;

	c = va_arg(*args, int);
	len = 1;
	if (!flags.left)
		print_padding(flags.width, len, ' ', char_count);
	*char_count += write(1, &c, 1);
	if (flags.left)
		print_padding(flags.width, len, ' ', char_count);
}

void	print_string(t_flags flags, va_list *args, int *char_count)
{
	char	*s;
	int		len;

	s = va_arg(*args, char *);
	if (!s)
		len = 6;
	else
		len = ft_strlen(s);
	if (s && flags.dot && flags.precision < len)
		len = flags.precision;
	else if (!s && flags.dot && flags.precision < len)
		len = 0;
	if (!flags.left)
		print_padding(flags.width, len, ' ', char_count);
	if (!s && (!flags.dot || flags.precision >= 6))
		*char_count += write(1, "(null)", 6);
	else if (s)
		*char_count += write(1, s, len);
	if (flags.left)
		print_padding(flags.width, len, ' ', char_count);
}

void	print_pointer(t_flags flags, va_list *args, int *char_count)
{
	void	*ptr;
	int		len;

	ptr = va_arg(*args, void *);
	if (!ptr)
		len = 5;
	else
		len = get_numlen((unsigned long)ptr, 16) + 2;
	if (!flags.left)
		print_padding(flags.width, len, ' ', char_count);
	if (!ptr)
		*char_count += write(1, "(nil)", 5);
	else
	{
		*char_count += write(1, "0x", 2);
		put_numbase((unsigned long)ptr, "0123456789abcdef", 16, char_count);
	}
	if (flags.left)
		print_padding(flags.width, len, ' ', char_count);
}
