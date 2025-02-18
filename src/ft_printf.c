/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwei <fwei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 22:45:47 by fwei              #+#    #+#             */
/*   Updated: 2024/12/18 21:24:26 by fwei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	process_str(const char *fmt, va_list *args, int *char_count)
{
	while (*fmt)
	{
		if (*fmt != '%')
		{
			*char_count += write(1, fmt, 1);
			fmt++;
		}
		else
		{
			fmt++;
			process_format(fmt, args, char_count);
			while (*fmt && !ft_strchr("cspdiuxX%", *fmt))
				fmt++;
			if (*fmt)
				fmt++;
		}
	}
}

int	ft_printf(const char *format_str, ...)
{
	va_list	args;
	int		char_count;

	char_count = 0;
	if (!format_str)
		return (-1);
	va_start(args, format_str);
	process_str(format_str, &args, &char_count);
	va_end(args);
	return (char_count);
}
