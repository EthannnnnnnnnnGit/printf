/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-kerc <eel-kerc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 12:30:34 by eel-kerc          #+#    #+#             */
/*   Updated: 2025/12/23 14:16:14 by eel-kerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_zero(t_flags *flags)
{
	if (flags->zero_paded && flags->precision == 0)
	{
		while ((size_t)flags->decay > flags->len_arg)
		{
			write(1, "0", 1);
			flags->len_arg++;
		}
	}
	if (flags->precision != -1)
	{
		while (flags->precision)
		{
			write(1, "0", 1);
			flags->precision--;
		}
	}
}

void	print_hexa(uintptr_t val, char *base)
{
	if (val >= 16)
		print_hexa(val / 16, base);
	write(1, &base[val % 16], 1);
}

size_t	print_number_base(t_flags *flags, va_list arg, char *base)
{
	unsigned int	nbr;

	nbr = (unsigned int)va_arg(arg, int);
	flags->len_arg = count_hexa_len(nbr, flags);
	flags->precision = get_max((flags->precision - flags->len_arg), 0);
	flags->len_arg += flags->precision;
	writing_flags(flags, false);
	if (flags->hashtag && (flags->type == 'x' || flags->type == 'X')
		&& nbr != 0)
	{
		write(1, "0", 1);
		write(1, &(flags->type), 1);
	}
	write_zero(flags);
	print_hexa(nbr, base);
	return (writing_flags(flags, true));
}
