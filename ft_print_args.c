/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-kerc <eel-kerc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 21:56:52 by eel-kerc          #+#    #+#             */
/*   Updated: 2025/12/03 16:39:56 by eel-kerc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_flags(char *f_temp, t_flags *flags)
{
	size_t	i;

	flags->negative_decay = char_in_str(f_temp, '-');
	flags->zero_paded = char_in_str(f_temp, '0');
	flags->hashtag = char_in_str(f_temp, '#');
	flags->space = char_in_str(f_temp, ' ');
	flags->pos_sign = char_in_str(f_temp, '+');
	flags->len_flags += (ft_strlen(f_temp) + 2);
	flags->decay = getting_decay_len(f_temp);
	if (char_in_str(f_temp, '.'))
	{
		i = 0;
		flags->precision = 0;
		while (f_temp[i] == '-' || f_temp[i] == '0' || f_temp[i] == '#' || f_temp[i] == ' '
		|| f_temp[i] == '+' || (f_temp[i] >= '0' && f_temp[i] <= '9'))
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

void	print_decay(t_flags *flags)
{
	char	c;

	if (flags->zero_paded && flags->decay > 0 && (flags->type != 'c'
			&& flags->type != 's' && flags->type != '%' && flags->type != 'p'))
		c = '0';
	else
		c = ' ';
	while (flags->decay > (int)flags->len_arg)
	{
		write(1, &c, 1);
		flags->decay--;
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

void	decrease_decay_flags(t_flags *flags)
{
	if (flags->pos_sign && (flags->type == 'p' || flags->type == 'i' || flags->type == 'd'))
		flags->decay -= 1;
	else if (flags->space
		&& (flags->type == 'p' || flags->type == 'i' || flags->type == 'd'))
		flags->decay -= 1;
	if (flags->decay < 0)
		flags->decay = 0;
}

size_t	writing_flags(t_flags *flags,bool printed)
{
	int	bytes_flags;
	int	temp_decay;

	temp_decay = flags->decay;
	bytes_flags = flags->decay - flags->len_arg;
	decrease_decay_flags(flags);
	if (!printed && !flags->negative_decay)
		print_decay(flags);
	if (printed && flags->negative_decay)
		print_decay(flags);
	flags->decay = temp_decay;
	if (bytes_flags < 0)
		return (flags->len_arg);
	return (bytes_flags + flags->len_arg);
}
