/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decay.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-kerc <eel-kerc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 21:56:52 by eel-kerc          #+#    #+#             */
/*   Updated: 2026/11/02 10:52:53 by eel-kerc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_precision(char *f_temp, t_flags *flags)
{
	size_t	i;

	if (char_in_str(f_temp, '.'))
	{
		i = 0;
		flags->precision = 0;
		while (f_temp[i] == '-' || f_temp[i] == '0'
			|| f_temp[i] == '#' || f_temp[i] == ' ' || f_temp[i] == '+'
			|| (f_temp[i] >= '0' && f_temp[i] <= '9'))
			i++;
		i++;
		while (f_temp[i] >= '0' && f_temp[i] <= '9')
		{
			flags->precision = (flags->precision * 10) + (f_temp[i] - '0');
			i++;
		}
	}
	else
		flags->precision = -1;
}

void	init_flags(char *f_temp, t_flags *flags)
{
	size_t	i;

	i = 0;
	flags->negative_decay = char_in_str(f_temp, '-');
	flags->zero_paded = 0;
	while (f_temp[i] == '-' || f_temp[i] == '0' || f_temp[i] == '#'
		|| f_temp[i] == ' ' || f_temp[i] == '+')
	{
		if (f_temp[i] == '0')
			flags->zero_paded = 1;
		i++;
	}
	flags->hashtag = char_in_str(f_temp, '#');
	flags->space = char_in_str(f_temp, ' ');
	flags->sign = char_in_str(f_temp, '+');
	flags->len_flags += (ft_strlen(f_temp) + 2);
	flags->decay = getting_decay_len(f_temp);
	get_precision(f_temp, flags);
}

void	print_decay(t_flags *flags)
{
	char	c;

	c = ' ';
	if (!flags->zero_paded)
	{
		while (flags->decay > (int)flags->len_arg)
		{
			write(1, &c, 1);
			flags->decay--;
		}
	}
}

int	getting_decay_len(char *f_temp)
{
	int	i;
	int	decay;

	i = 0;
	while (f_temp[i] == '-' || f_temp[i] == '0' || f_temp[i] == '#'
		|| f_temp[i] == ' ' || f_temp[i] == '+')
		i++;
	decay = 0;
	while (f_temp[i] >= '0' && f_temp[i] <= '9')
	{
		decay = (decay * 10) + (f_temp[i] - '0');
		i++;
	}
	return (decay);
}

size_t	writing_flags(t_flags *flags, bool printed)
{
	int	bytes_flags;
	int	temp_decay;

	temp_decay = flags->decay;
	bytes_flags = flags->decay - flags->len_arg;
	if (!printed && !flags->negative_decay)
		print_decay(flags);
	if (printed && flags->negative_decay)
		print_decay(flags);
	flags->decay = temp_decay;
	if (bytes_flags < 0)
		return (flags->len_arg);
	return (bytes_flags + flags->len_arg);
}
