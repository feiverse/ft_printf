/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwei <fwei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:34:50 by fwei              #+#    #+#             */
/*   Updated: 2024/12/01 03:50:41 by fwei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	v;

	v = 0;
	while (s1[v] && s1[v] == s2[v] && v < n)
		v++;
	if (v < n)
		return ((unsigned char) s1[v] - (unsigned char) s2[v]);
	return (0);
}
