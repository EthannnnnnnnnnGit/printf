/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-kerc <eel-kerc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 12:12:21 by eel-kerc          #+#    #+#             */
/*   Updated: 2025/12/03 16:25:45 by eel-kerc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_pointer(uintptr_t ptr)
{
	char	*base;

	base = "0123456789abcdef";
	if (ptr >= 16)
		print_pointer(ptr / 16);
	write(1, &base[ptr % 16], 1);
}

size_t	print_number_base(t_flags *flags, va_list arg, char *base)
{
	unsigned int	nbr;
	unsigned long	divide;
	char			c;

	nbr = (unsigned int)va_arg(arg, int);
	flags->len_arg = count_hexa_len(nbr, flags);
	writing_flags(flags, false);
	if (flags->hashtag && (flags->type == 'x' || flags->type == 'X') && nbr != 0)
	{
		write(1, "0", 1);
		write(1, &(flags->type), 1);
	}
	flags->len_arg = get_size_nb(flags);
	divide = 1;
	while (divide <= nbr)
		divide *= 16;
	divide /= 16;
	while (divide >= 16)
	{
		c = base[nbr / divide];
		write(1, &c, 1);
		nbr %= divide;
		divide /= 16;
	}
	c = base[nbr];
	write(1, &c, 1);
	return (writing_flags(flags, true));
}

void	print_positive(unsigned int nbr)
{
	char	nb;

	if (nbr >= 10)
		print_positive(nbr / 10);
	nb = nbr % 10 + '0';
	write(1, &nb, 1);
}

void	print_sign(t_flags *flags, int *nbr)
{
	if (!flags->zero_paded)
		writing_flags(flags, false);
	if (!flags->pos_sign && *nbr >= 0 && flags->space)
		write(1, " ", 1);
	if (flags->pos_sign && *nbr >= 0)
		write(1, "+", 1);
	if (*nbr < 0)
	{
		write(1, "-", 1);
		*nbr *= -1;
	}
	while (flags->precision != (int)flags->len_arg)
	{
		flags->len_arg++;
		write(1, "0", 1);
	}
	if (!flags->zero_paded)
		writing_flags(flags, false);
}

size_t	print_number(t_flags *flags, va_list arg, char type)
{
	int	nbr;

	flags->type = type;
	if (flags->type == 'u')
	{
		nbr = (unsigned int)va_arg(arg, unsigned int);
		flags->len_arg = count_nb_uint(nbr);
		flags->precision = get_size_nb(flags);
		writing_flags(flags, false);
		print_positive(nbr);
		return (writing_flags(flags, true));
	}
	else
	{
		nbr = (int)va_arg(arg, int);
		if (nbr == -2147483648)
		{
			flags->len_arg = 11;
			flags->precision = get_size_nb(flags);
			writing_flags(flags, false);
			write(1, "-2147483648", 11);
			return (writing_flags(flags, true));
		}
		flags->len_arg = count_nb_int(nbr, flags);
		flags->precision = get_size_nb(flags);
		print_sign(flags, &nbr);
		print_positive(nbr);
		return (writing_flags(flags, true));
	}
}
