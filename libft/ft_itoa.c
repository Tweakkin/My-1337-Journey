/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboukhmi <yboukhmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 14:26:42 by yboukhmi          #+#    #+#             */
/*   Updated: 2025/10/18 22:00:33 by yboukhmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(int n)
{
	int	digits_count;

	digits_count = 0;
	while (n != 0)
	{
		n /= 10;
		digits_count++;
	}
	return (digits_count);
}

static long	handle_negative(char *s, long num)
{
	if (num < 0)
	{
		num = -num;
		s[0] = '-';
	}
	return (num);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		slen;
	long	num;

	if (n == 0)
		return (ft_strdup("0"));
	slen = count_digits(n);
	if (n < 0)
		slen++;
	str = malloc(sizeof(char) * (slen + 1));
	if (!str)
		return (NULL);
	num = handle_negative(str, (long)n);
	str[slen] = '\0';
	while (num != 0)
	{
		str[slen - 1] = num % 10 + '0';
		num /= 10;
		slen--;
	}
	return (str);
}
