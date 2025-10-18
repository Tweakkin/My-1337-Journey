/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboukhmi <yboukhmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 11:53:56 by yboukhmi          #+#    #+#             */
/*   Updated: 2025/10/16 12:13:41 by yboukhmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dst1;
	const unsigned char	*src1;

	dst1 = (unsigned char *)dst;
	src1 = (const unsigned char *)src;
	if (dst == src || len == 0)
		return (dst);
	if (dst < src)
		ft_memcpy(dst1, src1, len);
	else
	{
		while (len > 0)
		{
			dst1[len - 1] = src1[len - 1];
			len--;
		}
	}
	return (dst);
}
