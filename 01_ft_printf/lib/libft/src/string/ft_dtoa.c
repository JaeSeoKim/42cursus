/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 19:46:06 by jaeskim           #+#    #+#             */
/*   Updated: 2020/10/29 22:31:35 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char	*ft_custom_itoa(long exponent, int sign)
{
	char			*tmp;
	char			*result;

	if (!sign)
		return (ft_convert_base_unsigned(exponent, "0123456789", 10));
	tmp = ft_convert_base_unsigned(exponent, "0123456789", 10);
	result = ft_strjoin("-", tmp);
	free(tmp);
	return (result);
}

static char	*ft_round_char(
	char round_flag,
	int precision,
	char *result,
	long *exponent)
{
	while (--precision >= 0)
	{
		if (result[precision] + round_flag > '9')
		{
			round_flag = 1;
			result[precision] = '0';
		}
		else
		{
			result[precision] += round_flag;
			round_flag = 0;
		}
	}
	if (round_flag)
		++(*exponent);
	return (result);
}

static char	*ft_round_with_precision(
	double mantissa,
	int precision,
	long *exponent)
{
	int		i;
	long	tmp;
	char	*result;
	char	round_flag;

	if (!(result = malloc(sizeof(char) * (precision + 1))))
		return (0);
	i = 0;
	while (i < precision)
	{
		mantissa *= 10;
		tmp = (long)mantissa;
		result[i++] = tmp + '0';
		mantissa -= tmp;
	}
	result[precision] = 0;
	round_flag = 0;
	mantissa *= 10;
	tmp = (long)(mantissa);
	if ((precision % 2 == 0 ? \
		(long)(mantissa * 10) > 5 : (long)(mantissa * 10) >= 5))
		++tmp;
	return (ft_round_char(tmp >= 5 ? 1 : 0, \
		precision, result, exponent));
}

static char	*ft_make_float_string(
	long exponent,
	double mantissa,
	int precision,
	union u_double n)
{
	char			*tmp;
	char			*tmp2;
	char			*result;

	tmp = ft_round_with_precision(mantissa, precision, &exponent);
	tmp2 = ft_custom_itoa(exponent, n.sign);
	result = ft_strjoin(tmp2, ".");
	free(tmp2);
	result = ft_strjoin_with_frees(result, tmp);
	return (result);
}

char		*ft_dtoa(double n, int precision)
{
	union u_double	num;
	long			exponent;
	double			mantissa;

	num.d = n;
	exponent = (long)n;
	mantissa = n - (double)exponent;
	if (exponent < 0)
		exponent = -exponent;
	mantissa = mantissa < 0 ? -mantissa : mantissa;
	if (precision == 0)
	{
		if ((exponent % 2 == 0 ? \
			(long)(mantissa * 10) > 5 : (long)(mantissa * 10) >= 5))
			++exponent;
		return (ft_custom_itoa(exponent, num.sign));
	}
	return (ft_make_float_string(exponent, mantissa, precision, num));
}
