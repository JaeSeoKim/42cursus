/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ullitoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 21:02:14 by jaeskim           #+#    #+#             */
/*   Updated: 2020/10/19 22:42:06 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_count_digist(long long int n)
{
	size_t count;

	count = 0;
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static void		ft_write_nbrber(char *dest, unsigned long long int n)
{
	if (n < 10)
		*dest = n + '0';
	else
	{
		*dest = n % 10 + '0';
		ft_write_nbrber(dest - 1, n / 10);
	}
}

char			*ft_ullitoa(
	unsigned long long int n,
	t_format *pf)
{
	char					*result;
	size_t					len;

	if (n == 0 && pf->precision == 0 && pf->visit_precision == 1)
		return (ft_strdup(""));
	if (n == 0)
		return (ft_strdup("0"));
	else
	{
		len = ft_count_digist(n);
		if (!(result = (char *)malloc(sizeof(char) * (len + 1))))
			return (0);
		ft_write_nbrber((result + len - 1), n);
		result[len] = '\0';
	}
	return (result);
}
