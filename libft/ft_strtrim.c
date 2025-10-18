/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboukhmi <yboukhmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 21:11:37 by yboukhmi          #+#    #+#             */
/*   Updated: 2025/10/17 21:31:43 by yboukhmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start_index;
	size_t	end_index;
	char	*trimmed_str;

	if (!s1 || !set)
		return (NULL);
	if (set[0] == '\0')
		return (ft_strdup(s1));
	start_index = 0;
	end_index = ft_strlen(s1);
	while (s1[start_index] && ft_strchr(set, s1[start_index]))
		start_index++;
	while (end_index > start_index && ft_strchr(set, s1[end_index - 1]))
		end_index--;
	trimmed_str = malloc((end_index - start_index + 1) * sizeof(char));
	if (!trimmed_str)
		return (NULL);
	ft_memcpy(trimmed_str, s1 + start_index, end_index - start_index);
	trimmed_str[end_index - start_index] = '\0';
	return (trimmed_str);
}
