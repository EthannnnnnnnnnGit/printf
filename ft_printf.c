/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-kerc <eel-kerc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 21:33:15 by eel-kerc          #+#    #+#             */
/*   Updated: 2025/12/03 14:12:54 by eel-kerc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	iterating_message(const char *str, int i)
{
	int	j;

	j = 0;
	while (str[i + j] && str[i + j] != '%')
		j++;
	write(1, &str[i], j);
	i += j;
	if (str[i] == '%')
		return (i + 1);
	return (i);
}

int	check_flags_good(char *flags)
{
	int	i;

	i = 0;
	while (flags[i] == '-' || flags[i] == '0' || flags[i] == '#'
		|| flags[i] == ' ' || flags[i] == '+')
		i++;
	while (flags[i] >= '0' && flags[i] <= '9')
		i++;
	if (flags[i] == '.')
	{
		i++;
		while (flags[i] >= '0' && flags[i] <= '9')
			i++;
	}
	if (flags[i])
		return (false);
	return (true);
}

t_flags	*getting_flags(const char *str, size_t *i, t_flags *flags)
{
	char	*f_temp;
	int		count;

	count = 0;
	while (str[*i] == '-' || str[*i] == '0' || str[*i] == '#' || str[*i] == ' '
		|| str[*i] == '.' || str[*i] == '+'
		|| (str[*i] >= '0' && str[*i] <= '9'))
	{
		count++;
		(*i)++;
	}
	f_temp = ft_substr(str, *i - count, count);
	if (!check_flags_good(f_temp))
	{
		free(flags);
		write(1, "%", 1);
		*i -= count;
		return (NULL);
	}
	init_flags(f_temp, flags);
	free(f_temp);
	return (flags);
}

int	print_str(const char *str, va_list arg)
{
	size_t	i;
	size_t	bytes;
	t_flags	*flags;

	bytes = 0;
	flags = malloc(sizeof(t_flags));
	if (!flags)
		return (-1);
	flags->len_flags = 0;
	i = 0;
	while (str[i])
	{
		i = iterating_message(str, i);
		if (str[i])
		{
			getting_flags(str, &i, flags);
			flags->type = str[i++];
			if (!check_is_percent(flags, &i, str))
				bytes += writing_arg(flags, arg);
			else
				bytes += 1;
		}
	}
	i = iterating_message(str, i);
	bytes = bytes + i - flags->len_flags;
	free(flags);
	return (bytes);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	size_t	bytes;

	if (!str)
		return (-1);
	va_start(arg, str);
	bytes = print_str(str, arg);
	va_end(arg);
	return (bytes);
}
