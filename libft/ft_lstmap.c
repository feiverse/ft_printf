/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwei <fwei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:22:57 by fwei              #+#    #+#             */
/*   Updated: 2024/12/01 21:27:16 by fwei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*index;
	t_list	*head;

	if (!lst || !f || !del)
		return (NULL);
	head = ft_lstnew(NULL);
	if (!head)
		return (NULL);
	index = head;
	while (lst)
	{
		index->content = f(lst->content);
		if (lst->next)
		{
			index = ft_lstnew(NULL);
			if (!index)
			{
				ft_lstclear(&head, del);
				return (NULL);
			}
			ft_lstadd_back(&head, index);
		}
		lst = lst->next;
	}
	return (head);
}
