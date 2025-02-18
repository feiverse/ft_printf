/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwei <fwei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 21:35:58 by fwei              #+#    #+#             */
/*   Updated: 2024/12/01 03:50:26 by fwei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	v;
	size_t	g;
	char	*new;

	new = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new)
		return (NULL);
	v = 0;
	while (s1[v])
	{
		new[v] = s1[v];
		v++;
	}
	g = 0;
	while (s2[g])
	{
		new[v + g] = s2[g];
		g++;
	}
	new[v + g] = '\0';
	return (new);
}
