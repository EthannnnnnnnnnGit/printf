/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-kerc <eel-kerc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 09:19:20 by eel-kerc          #+#    #+#             */
/*   Updated: 2025/11/17 10:39:56 by eel-kerc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	if (n == 0)
		return (0);
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (str1[i] && str1[i] == str2[i] && i < n - 1)
		i++;
	return (str1[i] - str2[i]);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*s1;
	char	*s2;

	s1 = "test";
	s2 = "";
	printf("%i\n", ft_strncmp(s1, s2, 2));
	printf("%i", strncmp(s1, s2, 2));
}*/
