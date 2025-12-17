/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-kerc <eel-kerc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 09:34:01 by eel-kerc          #+#    #+#             */
/*   Updated: 2025/11/20 13:34:49 by eel-kerc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*listo;
	t_list	*next;

	if (!lst || !(*del))
		return ;
	if (!*lst)
	{
		free(*lst);
		*lst = NULL;
		return ;
	}
	listo = *lst;
	while (listo)
	{
		next = listo->next;
		ft_lstdelone(listo, (*del));
		listo = next;
	}
	*lst = NULL;
}
