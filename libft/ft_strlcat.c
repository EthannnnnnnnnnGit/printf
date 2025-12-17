/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-kerc <eel-kerc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 13:43:10 by eel-kerc          #+#    #+#             */
/*   Updated: 2025/11/19 09:54:45 by eel-kerc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	i;
	size_t	j;

	len = ft_strlen(dst);
	i = 0;
	while (dst[i] && i < size)
		i++;
	if (dst[i] != '\0' || size == 0)
		return (size + ft_strlen(src));
	j = 0;
	while ((i + j < size - 1) && src[j])
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (len + ft_strlen(src));
}
