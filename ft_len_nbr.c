/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-kerc <eel-kerc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 12:56:25 by eel-kerc          #+#    #+#             */
/*   Updated: 2026/11/02 10:28:49 by eel-kerc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	count_ptr_len(uintptr_t arg)
{
	if (arg < 16)
		return (1);
	return (1 + count_ptr_len(arg / 16));
}

size_t	count_hexa_len(unsigned int arg, t_flags *flags)
{
	size_t	count;

	count = 1;
	while (arg >= 16)
	{
		count++;
		arg /= 16;
	}
	if (flags->hashtag && arg)
		return (count + 2);
	return (count);
}

size_t	count_nb_int(int arg, t_flags *flags)
{
	size_t	count;

	count = 1;
	if (arg < 0)
	{
		arg *= -1;
		flags->sign = 1;
	}
	while (arg >= 10)
	{
		count++;
		arg /= 10;
	}
	return (count);
}

size_t	count_nb_uint(unsigned int arg)
{
	size_t	count;

	count = 1;
	while (arg >= 10)
	{
		count++;
		arg /= 10;
	}
	return (count);
}
