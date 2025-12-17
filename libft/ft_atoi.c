/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-kerc <eel-kerc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 13:31:06 by eel-kerc          #+#    #+#             */
/*   Updated: 2025/11/20 15:57:21 by eel-kerc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	ft_isspace(char c)
{
	if (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	pos;
	int	res;

	i = 0;
	res = 0;
	while (ft_isspace(nptr[i]))
		i++;
	pos = 1;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i++] == '-')
			pos *= -1;
	}
	while (nptr[i] <= '9' && nptr[i] >= '0')
	{
		res = res * 10 + (nptr[i] - 48);
		i++;
	}
	return (res * pos);
}
