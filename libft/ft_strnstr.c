/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-kerc <eel-kerc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 12:12:01 by eel-kerc          #+#    #+#             */
/*   Updated: 2025/11/20 16:09:54 by eel-kerc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (little[0] == '\0')
		return ((char *)&big[i]);
	while (i < len && big[i])
	{
		if (big[i] == little[j])
			j++;
		else
		{
			i -= j;
			j = 0;
		}
		if (little[j] == '\0')
			return ((char *)&big[i - j + 1]);
		i++;
	}
	return (NULL);
}
