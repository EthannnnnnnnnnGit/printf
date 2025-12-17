/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-kerc <eel-kerc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 07:11:58 by eel-kerc          #+#    #+#             */
/*   Updated: 2025/11/20 15:36:34 by eel-kerc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_trim(char c, const char *set)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(set);
	while (i < len)
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_count(const char *s1, const char *set)
{
	int	i;
	int	len;
	int	count;

	i = 0;
	len = ft_strlen(s1);
	count = 0;
	while (ft_is_trim(s1[i++], set))
		count++;
	i = len - 1;
	while (ft_is_trim(s1[i--], set) && count < len)
		count++;
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*strim;
	size_t	i;
	size_t	j;
	size_t	count;
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	count = ft_count(s1, set);
	len = ft_strlen(s1);
	strim = malloc((len - count + 1) * sizeof(char));
	if (!strim)
		return (NULL);
	i = 0;
	j = 0;
	while (ft_is_trim(s1[i], set))
		i++;
	while (len - count != 0)
	{
		strim[j++] = s1[i++];
		count++;
	}
	strim[j] = '\0';
	return (strim);
}
