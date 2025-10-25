/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboukhmi <yboukhmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 12:30:29 by yboukhmi          #+#    #+#             */
/*   Updated: 2025/10/24 17:53:37 by yboukhmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dstlen;

	if (!dst && dstsize == 0)
		return (ft_strlen(src));
	i = 0;
	j = 0;
	while (dst[i] != '\0')
		i++;
	dstlen = i;
	if (dstsize == 0)
		return (dstlen + ft_strlen(src));
	if (dstlen >= dstsize)
		return (dstsize + ft_strlen(src));
	while (src[j] != '\0' && i < dstsize - 1)
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (dstlen + ft_strlen(src));
}
