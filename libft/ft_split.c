/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboukhmi <yboukhmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 21:32:27 by yboukhmi          #+#    #+#             */
/*   Updated: 2025/10/18 10:41:19 by yboukhmi         ###   ########.fr       */
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
	return count;
}

static int	add_words(char **splitted, char *s, char c)
{

}

char	**ft_split(char const *s, char c)
{
	char	**splitted;
	size_t	strings;
	size_t	i;
	
	i = 0;
	if (!s)
		return (NULL);
	strings = count_words(s, c);
	splitted = ((strings + 1) * sizeof(char *));
	if (!splitted)
		return (NULL);
	while (i < strings)
	{
		add_words(splitted, s, c);
	}
	
	
}

int main()
{
	char c[]= "cups of the  rose";
	printf("%d", count_words(c, ' '));
}