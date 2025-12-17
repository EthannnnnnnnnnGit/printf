/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-kerc <eel-kerc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 13:00:42 by eel-kerc          #+#    #+#             */
/*   Updated: 2025/12/03 13:34:52 by eel-kerc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_int_len(int n)
{
	int	count;

	count = 1;
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n >= 10)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_int_len(n);
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n < 0)
	{
		n *= -1;
		str[0] = '-';
	}
	while (n >= 10)
	{
		str[len - 1] = n % 10 + '0';
		n /= 10;
		len--;
	}
	str[len - 1] = n + '0';
	return (str);
}
