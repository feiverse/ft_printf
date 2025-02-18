/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwei <fwei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 04:22:03 by fwei              #+#    #+#             */
/*   Updated: 2024/12/01 03:49:42 by fwei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	v;

	v = 0;
	while (v < n)
	{
		if (*(unsigned char *)(s + v) == (unsigned char)c)
			return ((void *)s + v);
		v++;
	}
	return (NULL);
}
