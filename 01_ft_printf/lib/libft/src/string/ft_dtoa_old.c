/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa_old.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 19:46:06 by jaeskim           #+#    #+#             */
/*   Updated: 2020/11/02 21:14:31 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

static char	*ft_round_with_precision(long n, int precision, long *exponent)
{
	char	tmp;
	char	round_flag;
	char	*result;

	if (!(result = malloc(sizeof(char) * (precision + 1))))
		return (0);
	round_flag = (n % 10) >= 5 ? 1 : 0;
	n = n / 10;
	result[precision--] = 0;
	while (precision >= 0)
	{
		if ((tmp = ((n % 10) + round_flag)) >= 10)
			round_flag = 1;
		else
			round_flag = 0;
		result[precision--] = tmp >= 10 ? '0' : tmp + '0';
		n = n / 10;
	}
	if (precision >= 0 && round_flag)
		result[precision--] = '1';
	else if (round_flag)
		++(*exponent);
	while (precision >= 0)
		result[precision--] = '0';
	return (result);
}

char		*ft_dtoa(double n, int precsion)
{
	char		*result;\
	char		*tmp;
	char		*tmp2;
	long		exponent;
	double		mantissa;

	exponent = (long)n;
	mantissa = n - (double)exponent;
	mantissa = mantissa < 0 ? -mantissa : mantissa;
	if (exponent < 0)
		exponent = -exponent;
	if (precsion == 0 && (exponent % 2 == 0 ? \
		(long)(mantissa * 10) > 5 : (long)(mantissa * 10) >= 5))
		++exponent;
	if (precsion == 0)
		return (ft_custom_itoa(n, exponent));
	tmp = ft_round_with_precision(\
		mantissa * 1e+52, precsion, &exponent);
	tmp2 = ft_custom_itoa(n, exponent);
	result = ft_strjoin(tmp2, ".");
	free(tmp2);
	result = ft_strjoin_with_frees(result, tmp);
	return (result);
}
