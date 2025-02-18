/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwei <fwei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 17:39:49 by fwei              #+#    #+#             */
/*   Updated: 2024/12/01 21:49:35 by fwei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_words(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i] != '\0' && s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] != c)
			i++;
		count++;
		while (s[i] != '\0' && s[i] == c)
			i++;
	}
	return (count);
}

int	get_word_length(char const *s, char c)
{
	int	length;

	length = 0;
	while (s[length] != '\0')
	{
		if (s[length] == c)
			break ;
		length++;
	}
	return (length);
}

char	*get_word(char const *s, int word_length)
{
	int		i;
	char	*word;

	word = malloc(sizeof(char) * (word_length + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < word_length)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

void	free_split(char **result)
{
	int	i;

	i = 0;
	while (result[i] != NULL)
	{
		free(result[i]);
		i++;
	}
	free(result);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**result;

	if (!s)
		return (NULL);
	result = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		result[j] = get_word(s + i, get_word_length(s + i, c));
		if (!result[j])
			return (free_split(result), NULL);
		i += get_word_length(s + i, c);
		j++;
	}
	result[j] = NULL;
	return (result);
}
