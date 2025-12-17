/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-kerc <eel-kerc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:18:53 by eel-kerc          #+#    #+#             */
/*   Updated: 2025/11/17 10:07:49 by eel-kerc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*destt;
	unsigned char	*srcc;

	destt = (unsigned char *)dest;
	srcc = (unsigned char *)src;
	if (destt == srcc)
		return (dest);
	if (destt > srcc && &srcc[n] > destt)
	{
		while (n > 0)
		{
			n--;
			destt[n] = srcc[n];
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
