/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwei <fwei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:53:44 by fwei              #+#    #+#             */
/*   Updated: 2024/12/01 03:50:50 by fwei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_char_set(char g, char const *set)
{
	size_t	v;

	v = 0;
	while (set[v])
	{
		if (set[v] == g)
			return (1);
		v++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	v;
	size_t	end;
	size_t	start;
	char	*str;

	start = 0;
	while (s1[start] && ft_char_set(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_char_set(s1[end - 1], set))
		end--;
	str = (char *)malloc(sizeof(*s1) * (end - start + 1));
	if (!str)
		return (NULL);
	v = 0;
	while (start < end)
		str[v++] = s1[start++];
	str[v] = 0;
	return (str);
}
