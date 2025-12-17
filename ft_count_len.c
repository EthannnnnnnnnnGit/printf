/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-kerc <eel-kerc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 12:56:25 by eel-kerc          #+#    #+#             */
/*   Updated: 2025/12/03 16:29:48 by eel-kerc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	get_max(size_t nb1, size_t nb2)
{
	if (nb1 > nb2)
		return (nb1);
	return (nb2);
}

size_t	get_size_nb(t_flags *flags)
{
	if (flags->precision != -1)
		return (get_max(flags->precision, flags->len_arg));
	return (flags->len_arg);
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

size_t	count_ptr_len(uintptr_t arg)
{
	if (arg < 16)
		return (1);
	return (1 + count_ptr_len(arg / 16));
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
	if ((flags->pos_sign && arg >= 0) || (flags->space && arg >= 0))
		count++;
	if (arg < 0)
	{
		count++;
		arg *= -1;
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
