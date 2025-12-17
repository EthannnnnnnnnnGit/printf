/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-kerc <eel-kerc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 09:53:24 by eel-kerc          #+#    #+#             */
/*   Updated: 2025/11/20 13:22:07 by eel-kerc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lista;
	t_list	*head;
	void	*content;

	if (!lst || !(*del) || !(*f))
		return (NULL);
	head = NULL;
	while (lst)
	{
		content = (*f)(lst->content);
		lista = ft_lstnew(content);
		if (!lista)
		{
			(*del)(content);
			ft_lstclear(&head, (*del));
			return (NULL);
		}
		ft_lstadd_back(&head, lista);
		lst = lst->next;
	}
	return (head);
}
