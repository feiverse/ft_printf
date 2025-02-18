/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwei <fwei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 19:12:30 by fwei              #+#    #+#             */
/*   Updated: 2024/12/18 22:08:26 by fwei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	put_nchars(int n, char c)
{
	int	v;

	v = 0;
	while (v++ < n)
		write(1, &c, 1);
	return (n);
}

int	get_numlen(unsigned long num, unsigned int baselen)
{
	int	len;

	len = 1;
	while (num >= baselen)
	{
		len++;
		num /= baselen;
	}
	return (len);
}

long	ft_ads(long n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

void	put_numbase(unsigned long num, char *base, unsigned int baselen, \
		int *char_count)
{
	if (num >= baselen)
	{
		put_numbase(num / baselen, base, baselen, char_count);
		*char_count += write(1, &base[num % baselen], 1);
	}
	else
		*char_count += write(1, &base[num], 1);
}
