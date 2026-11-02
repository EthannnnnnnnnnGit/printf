/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-kerc <eel-kerc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 13:39:34 by eel-kerc          #+#    #+#             */
/*   Updated: 2025/12/23 14:16:14 by eel-kerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_max(int nb1, int nb2)
{
	if (nb1 > nb2)
		return (nb1);
	return (nb2);
}

size_t	get_min(size_t nb1, size_t nb2)
{
	if (nb1 > nb2)
		return (nb2);
	return (nb1);
}

size_t	get_size_str(t_flags *flags, char *str)
{
	if (flags->precision != -1)
	{
		if (!str)
			return (get_min(flags->precision, 6));
		return (get_min(flags->precision, ft_strlen(str)));
	}
	else
	{
		if (!str)
			return (6);
		return (ft_strlen(str));
	}
}

int	char_in_str(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i++] == c)
			return (true);
	}
	return (false);
}
