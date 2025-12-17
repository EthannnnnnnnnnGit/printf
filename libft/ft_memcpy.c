/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-kerc <eel-kerc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:46:45 by eel-kerc          #+#    #+#             */
/*   Updated: 2025/11/24 10:27:15 by eel-kerc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*destt;
	char	*srcc;

	if (!src && !dest)
		return (NULL);
	i = 0;
	destt = (char *)dest;
	srcc = (char *)src;
	while (i < n)
	{
		destt[i] = srcc[i];
		i++;
	}
	return (dest);
}
