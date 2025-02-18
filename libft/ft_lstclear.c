/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwei <fwei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:49:16 by fwei              #+#    #+#             */
/*   Updated: 2024/12/01 04:01:20 by fwei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*index;
	t_list	*tmp;

	if (!(*lst) || !del)
		return ;
	index = (*lst);
	while (index)
	{
		tmp = index->next;
		del(index->content);
		free(index);
		index = tmp;
	}
	(*lst) = NULL;
}
