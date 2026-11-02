/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-kerc <eel-kerc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 21:57:09 by eel-kerc          #+#    #+#             */
/*   Updated: 2025/12/23 14:27:15 by eel-kerc         ###   ########.fr       */
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
	int		sign;
	int		decay;
	char	type;
	size_t	len_arg;
	size_t	len_flags;
}	t_flags;

int		ft_printf(const char *str, ...);
int		print_str(const char *str, va_list arg);
void	*getting_flags(const char *str, size_t *i, t_flags *flags);
int		check_flags_good(char *flags);
int		iterating_message(const char *str, int i);
size_t	writing_arg(t_flags *flags, va_list arg);
char	check_is_percent(t_flags *flags, size_t *i, const char *str);
size_t	writing_pointer(t_flags *flags, va_list arg);
size_t	writing_string(t_flags *flags, va_list arg);
size_t	writing_char(t_flags *flags, va_list arg);
size_t	writing_flags(t_flags *flags, bool printed);
int		getting_decay_len(char *flags);
void	print_decay(t_flags *flags);
void	init_flags(char *f_temp, t_flags *flags);
void	get_precision(char *f_temp, t_flags *flags);
size_t	count_nb_uint(unsigned int arg);
size_t	count_nb_int(int arg, t_flags *flags);
size_t	count_hexa_len(unsigned int arg, t_flags *flags);
size_t	count_ptr_len(uintptr_t arg);
int		char_in_str(char *str, char c);
size_t	get_size_str(t_flags *flags, char *str);
size_t	get_min(size_t nb1, size_t nb2);
int		get_max(int nb1, int nb2);
size_t	print_number(t_flags *flags, va_list arg, char type);
size_t	print_int(t_flags *flags, int nbr);
void	print_sign(t_flags *flags, int *nbr);
void	print_positive(unsigned int nbr);
size_t	print_number_base(t_flags *flags, va_list arg, char *base);
void	print_hexa(uintptr_t val, char *base);
void	write_zero(t_flags *flags);

#endif
