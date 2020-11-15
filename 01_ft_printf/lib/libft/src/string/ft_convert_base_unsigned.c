/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base_unsigned.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 19:56:00 by jaeskim           #+#    #+#             */
/*   Updated: 2020/11/15 16:29:27 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_digist(int64_t n, int base)
{
	size_t count;

	count = 0;
	while (n)
	{
		n /= base;
		count++;
	}
	return (count);
}

char			*ft_convert_base_unsigned(
	uint64_t num,
	const char *base_set,
	int base)
{
	char	*result;
	size_t	len;

	if (num == 0)
		return (ft_strdup("0"));
	len = ft_count_digist(num, base);
	if (!(result = malloc(sizeof(char) * (len + 1))))
		return (0);
	result[len] = 0;
	while (len)
	{
		result[--len] = base_set[num % base];
		num = num / base;
	}
	return (result);
}
