/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-kerc <eel-kerc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 21:57:09 by eel-kerc          #+#    #+#             */
/*   Updated: 2025/12/16 03:11:50 by eel-kerc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"
# include <stdbool.h>
# include <stdint.h>

typedef struct s_flags
{
	int		negative_decay;
	int		zero_paded;
	int		precision;
	int		hashtag;
	int		space;
	int		pos_sign;
	int		decay;
	char	type;
	size_t	len_arg;
	size_t	len_flags;
}	t_flags;

int		ft_printf(const char *str, ...);
int		print_str(const char *str, va_list arg);
t_flags	*getting_flags(const char *str, size_t *i, t_flags *flags);
int		check_flags_good(char *flags);
int		iterating_message(const char *str, int i);
size_t	writing_arg(t_flags *flags, va_list arg);
char	check_is_percent(t_flags *flags, size_t *i, const char *str);
void	decrease_decay_flags(t_flags *flags);
int		getting_decay_len(char *flags);
void	print_decay(t_flags *flags);
size_t	writing_flags(t_flags *flags, bool printed);
size_t	count_nb_uint(unsigned int arg);
size_t	count_nb_int(int arg, t_flags *flags);
size_t	count_nb_uint(unsigned int arg);
size_t	count_hexa_len(unsigned int arg, t_flags *flags);
int		char_in_str(char *str, char c);
size_t	writing_pointer(t_flags *flags, va_list arg);
size_t	writing_percent(t_flags *flags);
size_t	writing_string(t_flags *flags, va_list arg);
size_t	writing_char(t_flags *flags, va_list arg);
size_t	print_number(t_flags *flags, va_list arg, char type);
void	print_positive(unsigned int nbr);
size_t	print_number_base(t_flags *flags, va_list arg, char *base);
void	print_pointer(uintptr_t ptr);
size_t	count_ptr_len(uintptr_t arg);
void	print_sign(t_flags *flags, int *nbr);
void	init_flags(char *f_temp, t_flags *flags);
size_t	get_min(size_t nb1, size_t nb2);
size_t	get_max(size_t nb1, size_t nb2);
size_t	get_size_str(t_flags *flags, char *str);
size_t	get_size_nb(t_flags *flags);

#endif
