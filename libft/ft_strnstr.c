/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwei <fwei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:39:00 by fwei              #+#    #+#             */
/*   Updated: 2024/12/01 21:46:40 by fwei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	v;
	size_t	g;
	size_t	len_n;

	if (ft_strlen(little) == 0)
		return ((char *) big);
	len_n = ft_strlen(little);
	v = 0;
	while (big[v] && v < len)
	{
		g = 0;
		while (big[v + g] && big[v + g] == little[g] && v + g < len)
			g++;
		if (g == len_n)
			return ((char *) big + v);
		v++;
	}
	return (NULL);
}
