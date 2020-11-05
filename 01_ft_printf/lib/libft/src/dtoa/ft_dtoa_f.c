/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 21:15:58 by jaeskim           #+#    #+#             */
/*   Updated: 2020/11/05 20:17:36 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_dtoa_util.h"

static void	ft_round_flag(
	int *precision,
	t_ll mantissa,
	char **result,
	int *round_flag)
{
	char	tmp;

	while (*precision >= 0)
	{
		if ((tmp = ((mantissa % 10) + *round_flag)) >= 10)
			*round_flag = 1;
		else
			*round_flag = 0;
		(*result)[(*precision)--] = tmp >= 10 ? '0' : tmp + '0';
		mantissa = mantissa / 10;
	}
	if (precision >= 0 && *round_flag)
		(*result)[(*precision)--] = '1';
}

static char	*ft_round_with_precision(
	t_double decimal,
	int precision,
	long *integer)
{
	t_ll	mantissa;
	char	*result;
	int		round_flag;

	mantissa = decimal.d * \
		(t_ll)ft_pow(10, precision > 16 ? 17 : precision + 1);
	round_flag = ft_dtoa_ut_check_round(\
		decimal, mantissa % 10, *integer, precision);
	mantissa = mantissa / 10;
	if (!(result = malloc(sizeof(char) * (precision + 1))))
		return (0);
	result[precision--] = 0;
	while (precision >= 16)
		result[precision--] = '0';
	ft_round_flag(&precision, mantissa, &result, &round_flag);
	if (precision >= 0 && round_flag)
		result[precision--] = '1';
	else if (round_flag)
		++(*integer);
	while (precision >= 0)
		result[precision--] = '0';
	return (result);
}

char		*ft_dtoa_f(t_double n, int precision)
{
	long		integer;
	t_double	decimal;
	char		*tmp;
	char		*result;

	integer = (long)n.d;
	decimal.d = n.d - integer;
	decimal.sign = 0;
	integer = integer < 0 ? -integer : integer;
	if (precision == 0)
	{
		integer += ft_dtoa_ut_check_round(\
			decimal, decimal.d * 10, integer, precision);
		return (ft_dtoa_ut_itoa(integer, n.sign));
	}
	tmp = ft_round_with_precision(\
		decimal, precision, &integer);
	result = ft_strjoin_free_first(ft_dtoa_ut_itoa(integer, n.sign), ".");
	return (ft_strjoin_free_both(result, tmp));
}
