/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwei <fwei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 04:26:25 by fwei              #+#    #+#             */
/*   Updated: 2024/12/01 03:49:46 by fwei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	v;

	v = 0;
	while (v < n && *(unsigned char *)(s1 + v) == *(unsigned char *)(s2 + v))
		v++;
	if (v < n)
		return (*(unsigned char *)(s1 + v) - *(unsigned char *)(s2 + v));
	return (0);
}
