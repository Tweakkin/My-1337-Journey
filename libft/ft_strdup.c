/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboukhmi <yboukhmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:48:46 by yboukhmi          #+#    #+#             */
/*   Updated: 2025/10/17 12:11:01 by yboukhmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str_copy;
	size_t	i;

	i = 0;
	str_copy = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!str_copy)
		return (NULL);
	ft_memcpy(str_copy, s1, ft_strlen(s1) + 1);
	return (str_copy);
}
