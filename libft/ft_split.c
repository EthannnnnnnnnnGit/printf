/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-kerc <eel-kerc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:22:05 by eel-kerc          #+#    #+#             */
/*   Updated: 2025/11/20 15:44:55 by eel-kerc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(const char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] && s[i] != c)
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

static int	ft_has_tof(char **split, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (split[i] == NULL)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_free(char **split, const char *s, char c)
{
	int	i;
	int	count;

	count = ft_count(s, c);
	if (ft_has_tof(split, count))
	{
		i = 0;
		while (i < count + 1)
		{
			free(split[i]);
			i++;
		}
		free(split);
		return (1);
	}
	return (0);
}

static void	ft_splitting(char **split, char c, const char *s)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] && s[i] != c)
			j = i;
		while (s[i] != c && s[i])
			i++;
		if (s[i] || s[i - 1] != c)
			split[k++] = ft_substr(s, j, i - j);
	}
	split[k] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**split;

	split = malloc(sizeof(char *) * (ft_count(s, c) + 1));
	if (!split)
		return (NULL);
	ft_splitting(split, c, s);
	if (ft_free(split, s, c))
		return (NULL);
	return (split);
}
