/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-kerc <eel-kerc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 14:07:48 by eel-kerc          #+#    #+#             */
/*   Updated: 2025/12/03 16:25:16 by eel-kerc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	writing_char(t_flags *flags, va_list arg)
{
	char	c;

	flags->len_arg = 1;
	c = va_arg(arg, int);
	writing_flags(flags, false);
	write(1, &c, 1);
	return (writing_flags(flags, true));
}

size_t	writing_string(t_flags *flags, va_list arg)
{
	size_t		i;
	char	*str;

	str = (char *)va_arg(arg, char *);
	flags->len_arg = get_size_str(flags, str);
	if (!str)
	{
		writing_flags(flags, false);
		write(1, "(null)", flags->len_arg);
		return (writing_flags(flags, true));
	}
	writing_flags(flags, false);
	i = 0;
	while (i < flags->len_arg)
		write(1, &str[i++], 1);
	return (writing_flags(flags, true));
}

size_t	writing_pointer(t_flags *flags, va_list arg)
{
	uintptr_t	ptr;

	ptr = (uintptr_t)va_arg(arg, uintptr_t);
	if (!ptr)
	{
		flags->len_arg = 5;
		writing_flags(flags, false);
		write(1, "(nil)", 5);
		return (writing_flags(flags, true));
	}
	flags->len_arg = count_ptr_len(ptr) + 2;
	writing_flags(flags, false);
	if (flags->pos_sign)
		write(1, "+", 1);
	else if (flags->space)
		write(1, " ", 1);
	write(1, "0x", 2);
	print_pointer(ptr);
	return (writing_flags(flags, true));
}

char	check_is_percent(t_flags *flags, size_t *i, const char *str)
{
	if (flags->type == '%')
	{
		while (str[*i - 1] != '%')
			(*i)--;
		write(1, "%", 1);
		return (true);
	}
	return (false);
}

size_t	writing_arg(t_flags *flags, va_list arg)
{
	if (flags->type == 'c')
		return (writing_char(flags, arg));
	else if (flags->type == 's')
		return (writing_string(flags, arg));
	else if (flags->type == 'p')
		return (writing_pointer(flags, arg));
	else if (flags->type == 'd')
		return (print_number(flags, arg, 'd'));
	else if (flags->type == 'i')
		return (print_number(flags, arg, 'i'));
	else if (flags->type == 'u')
		return (print_number(flags, arg, 'u'));
	else if (flags->type == 'x')
		return (print_number_base(flags, arg, "0123456789abcdef"));
	else if (flags->type == 'X')
		return (print_number_base(flags, arg, "0123456789ABCDEF"));
	else if (flags->type == '%')
		return (write(1, "%", 1));
	else
		return (write(1, &flags->type, 1));
}
