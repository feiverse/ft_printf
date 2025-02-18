/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwei <fwei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:23:51 by fwei              #+#    #+#             */
/*   Updated: 2024/12/01 21:44:58 by fwei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	v;
	size_t	w;

	v = 0;
	w = 0;
	while (dst[v] && v < size)
		v++;
	while (src[w] && (v + w + 1) < size)
	{
		dst[v + w] = src[w];
		w++;
	}
	if (v < size)
		dst[v + w] = '\0';
	return (v + ft_strlen(src));
}
