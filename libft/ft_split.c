/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboukhmi <yboukhmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 21:32:27 by yboukhmi          #+#    #+#             */
/*   Updated: 2025/10/18 14:23:13 by yboukhmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static size_t	count_leng(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static int	add_words(char **splitted, char const *s, char c, size_t strings)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	while (j < strings)
	{
		while (s[i] && s[i] == c)
			i++;
		splitted[j] = malloc(sizeof(char) * (count_leng(s + i, c) + 1));
		if (!splitted[j])
		{
			splitted[j] = NULL;
			return (-1);
		}
		while (s[i] && s[i] != c)
			splitted[j][k++] = s[i++];
		splitted[j][k] = '\0';
		k = 0;
		j++;
	}
	splitted[j] = NULL;
	return (0);
}

static void	free_allocated(char **splitted)
{
	size_t	i;

	i = 0;
	while (splitted[i])
	{
		free(splitted[i]);
		i++;
	}
	free(splitted);
}

char	**ft_split(char const *s, char c)
{
	char	**splitted;
	size_t	strings;
	int		res;

	if (!s)
		return (NULL);
	strings = count_words(s, c);
	splitted = malloc((strings + 1) * sizeof(char *));
	if (!splitted)
		return (NULL);
	res = add_words(splitted, s, c, strings);
	if (res == -1)
	{
		free_allocated(splitted);
		return (NULL);
	}
	return (splitted);
}
