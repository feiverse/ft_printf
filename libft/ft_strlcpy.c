/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwei <fwei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:16:34 by fwei              #+#    #+#             */
/*   Updated: 2024/12/01 21:45:06 by fwei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	v;

	if (!size)
		return (ft_strlen(src));
	v = 0;
	while (src[v] && (v < size - 1))
	{
		dst[v] = src[v];
		v++;
	}
	dst[v] = 0;
	return (ft_strlen(src));
}
