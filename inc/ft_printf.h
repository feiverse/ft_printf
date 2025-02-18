/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwei <fwei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 12:17:00 by fwei              #+#    #+#             */
/*   Updated: 2025/01/02 13:49:27 by fwei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdbool.h>

typedef struct s_flags
{
	bool	dot;
	bool	hash;
	bool	left;
	bool	plus;
	bool	zero;
	bool	space;
	int		width;
	int		precision;
	char	type;
}		t_flags;

int		ft_printf(const char *format_str, ...);
int		put_nchars(int n, char c);
int		get_numlen(unsigned long num, unsigned int baselen);
long	ft_ads(long n);
void	put_numbase(unsigned long nbr, char *base, \
			unsigned int base_len, int *char_count);
void	parse_format_flags(t_flags *flags, const char *fmt);
void	initialize_flags(t_flags *flags);
void	adjust_flags(t_flags *flags);
void	process_format(const char *fmt, va_list *args, int *char_count);
void	process_str(const char *fmt, va_list *args, int *char_count);
void	print_padding(int width, int len, char pad_char, int *char_count);
void	print_sign(int value, t_flags flags, int *char_count);
void	print_prefix(unsigned int v, t_flags flags, char *p, int *char_count);
void	print_num_padding(int precision, int num_len, int *char_count);
void	print_char(t_flags flags, va_list *args, int *char_count);
void	print_string(t_flags flags, va_list *args, int *char_count);
void	print_pointer(t_flags flags, va_list *args, int *char_count);
void	print_decimal(t_flags flags, va_list *args, int *char_count);
void	print_unsigned(t_flags flags, va_list *args, int *char_count);
void	print_hex(t_flags flags, va_list *args, int *char_count, char *base);

#endif
