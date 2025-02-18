/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwei <fwei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 19:51:16 by fwei              #+#    #+#             */
/*   Updated: 2024/12/01 21:33:36 by fwei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int		nb;
	int		sign;
	size_t	v;

	v = 0;
	nb = 0;
	sign = 1;
	while (nptr[v] == ' ' || ('\t' <= nptr[v] && nptr[v] <= '\r'))
		v++;
	if (nptr[v] == '+')
		v++;
	else if (nptr[v] == '-')
	{
		sign *= -1;
		v++;
	}
	while ('0' <= nptr[v] && nptr[v] <= '9')
	{
		nb = nb * 10 + nptr[v] - '0';
		v++;
	}
	return (nb * sign);
}
