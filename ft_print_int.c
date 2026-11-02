/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-kerc <eel-kerc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 12:12:21 by eel-kerc          #+#    #+#             */
/*   Updated: 2026/11/02 10:53:48 by eel-kerc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_positive(unsigned int nbr)
{
	char	nb;

	if (nbr == 0)
		return ;
	if (nbr >= 10)
		print_positive(nbr / 10);
	nb = nbr % 10 + '0';
	write(1, &nb, 1);
}

void	print_sign(t_flags *flags, int *nbr)
{
	if (!flags->zero_paded)
		writing_flags(flags, false);
	if (!flags->sign && flags->space)
	{
		write(1, " ", 1);
	}
	if (flags->sign && *nbr >= 0)
		write(1, "+", 1);
	if (*nbr < 0)
	{
		write(1, "-", 1);
		*nbr *= -1;
	}
}

size_t	print_int(t_flags *flags, int nbr)
{
	if (nbr == -2147483648)
	{
		flags->len_arg = 11;
		flags->precision = get_max((flags->precision - flags->len_arg), 0);
		flags->len_arg += flags->precision;
		writing_flags(flags, false);
		write_zero(flags);
		write(1, "-2147483648", 11);
		return (writing_flags(flags, true));
	}
	flags->len_arg = count_nb_int(nbr, flags);
	flags->precision = get_max((flags->precision - flags->len_arg), 0);
	flags->len_arg += flags->precision + get_max(flags->sign, flags->space);
	print_sign(flags, &nbr);
	write_zero(flags);
	print_positive(nbr);
	return (writing_flags(flags, true));
}

size_t	print_number(t_flags *flags, va_list arg, char type)
{
	int	nbr;

	flags->type = type;
	if (flags->type == 'u')
	{
		nbr = (unsigned int)va_arg(arg, unsigned int);
		flags->len_arg = count_nb_uint(nbr);
		flags->precision = get_max((flags->precision - flags->len_arg), 0);
		flags->len_arg += flags->precision;
		writing_flags(flags, false);
		write_zero(flags);
		print_positive(nbr);
		return (writing_flags(flags, true));
	}
	else
	{
		nbr = (int)va_arg(arg, int);
		return (print_int(flags, nbr));
	}
}
