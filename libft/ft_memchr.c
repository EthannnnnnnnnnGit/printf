/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-kerc <eel-kerc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 10:58:02 by eel-kerc          #+#    #+#             */
/*   Updated: 2025/11/17 10:43:18 by eel-kerc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s1;
	unsigned char	car;
	size_t			i;

	s1 = (unsigned char *) s;
	car = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		if (s1[i] == car)
			return (s1 + i);
		i++;
	}
	return (NULL);
}
