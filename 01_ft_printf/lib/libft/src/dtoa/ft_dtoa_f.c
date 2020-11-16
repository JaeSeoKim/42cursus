/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 21:15:58 by jaeskim           #+#    #+#             */
/*   Updated: 2020/11/17 05:27:27 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_dtoa_util.h"

static void	ft_dtoa_rounding2(
	char *integer,
	int *integer_len,
	int round_flag)
{
	char	tmp;
	int		i;

	ft_dta_ut_int_reverse(integer, *integer_len);
	i = 0;
	while (round_flag && i < *integer_len)
	{
		if ((tmp = integer[i] + round_flag) >= 10)
			round_flag = 1;
		else
			round_flag = 0;
		integer[i] = tmp >= 10 ? 0 : tmp;
		++i;
	}
	if (round_flag && i < FT_DBL_INT_MAX_ARR)
	{
		++integer[i];
		++(*integer_len);
	}
	ft_dta_ut_int_reverse(integer, *integer_len);
}

static void	ft_dtoa_rounding(
	char *integer,
	char *decimal,
	int *integer_len,
	int precision)
{
	int		round_flag;
	char	tmp;

	round_flag = ft_dtoa_ut_check_round((precision == 0 ? \
		integer[*integer_len - 1] : decimal[precision - 1]), \
		decimal, precision, 0);
	if (round_flag && (precision != 0 || precision < FT_DBL_MAX_ARR))
	{
		while (round_flag && precision-- > 0)
		{
			if (!((tmp = decimal[precision] + round_flag) >= 10))
				round_flag = 0;
			decimal[precision] = tmp >= 10 ? 0 : tmp;
		}
		if (precision >= 0 && round_flag)
			decimal[precision] = 1;
		else if (round_flag)
			ft_dtoa_rounding2(integer, integer_len, round_flag);
	}
	else if (round_flag)
		ft_dtoa_rounding2(integer, integer_len, round_flag);
}

static char	*ft_dtoa_int_to_str(
	char *integer,
	int integer_len,
	int exp)
{
	int		i;
	char	*result;

	if (!(result = malloc(sizeof(char) * (exp > 0 ? exp + 1 : 2))))
		return (0);
	if (exp < 0)
	{
		result[0] = integer[0] + '0';
		result[1] = 0;
	}
	else
	{
		i = 0;
		while (i < integer_len)
		{
			result[i] = integer[i] + '0';
			++i;
		}
		result[i] = 0;
	}
	return (result);
}

static char	*ft_dtoa_decimal_to_str(
	char *decimal,
	int precision)
{
	int		i;
	char	*result;

	if (!(result = malloc(sizeof(char) * (precision + 1))))
		return (0);
	i = 0;
	while (i < precision)
	{
		if (i < FT_DBL_MAX_ARR)
			result[i] = decimal[i] + '0';
		else
			result[i] = '0';
		++i;
	}
	result[i] = 0;
	return (result);
}

char		*ft_dtoa_f(union u_double n, int precision)
{
	char	integer[FT_DBL_INT_MAX_ARR];
	char	decimal[FT_DBL_MAX_ARR];
	char	*result;
	int		integer_len;

	integer_len = ft_dtoa_setup_integer(n, integer);
	ft_dtoa_setup_decimal(n, decimal);
	ft_dtoa_rounding(integer, decimal, &integer_len, precision);
	result = ft_dtoa_int_to_str(integer, integer_len, \
		n.bit.exponent - (long)FT_DBL_BIAS);
	if (n.bit.sign)
		result = ft_strjoin_free_second("-", result);
	if (precision == 0)
		return (result);
	result = ft_strjoin_free_first(result, ".");
	result = ft_strjoin_free_both(result, \
		ft_dtoa_decimal_to_str(decimal, precision));
	return (result);
}
