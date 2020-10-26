/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 19:46:06 by jaeskim           #+#    #+#             */
/*   Updated: 2020/10/26 22:28:44 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char	*ft_itoa_with_precision(long n, int precision, long *exponent)
{
	char	tmp;
	char	round_flag;
	char	*result;

	if (!(result = malloc(sizeof(char) * (precision))))
		return (0);
	round_flag = (n % 10) > 5;
	n = n / 10;
	result[precision--] = 0;
	while (n && precision >= 0)
	{
		if ((tmp = (n % 10 + round_flag)) >= 5)
		{
			round_flag = 1;
			result[precision--] = '0';
		}
		else
		{
			round_flag = 0;
			result[precision--] = tmp + '0';
		}
		n = n / 10;
	}
	if (precision >= 0 && round_flag)
		result[precision--] = '1';
	else
		++(*exponent);
	while (precision >= 0)
		result[precision--] = '0';
	return (result);
}

char		*ft_dtoa(long double n, int precsion)
{
	char		*tmp;
	char		*result;
	long		exponent;
	long double	mantissa;

	exponent = (long)n;
	mantissa = n - (long double)exponent;
	if (precsion == 0)
	{
		
	}
	tmp = ft_itoa_with_precision(\
		(long)((mantissa < 0 ? -mantissa : mantissa) *\
		ft_pow(10, precsion + 1)), precsion + 1, &exponent);
	return (result);
}
