/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa_e.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 20:05:49 by jaeskim           #+#    #+#             */
/*   Updated: 2020/11/14 01:25:25 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_dtoa_util.h"

static void	ft_dtoa_rounding2(
	char *integer,
	int *integer_len,
	int round_flag,
	int i)
{
	char	tmp;

	ft_dta_ut_int_reverse(integer, *integer_len);
	while (round_flag && i < *integer_len)
	{
		if (!((tmp = integer[i] + round_flag) >= 10))
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

static void	ft_dtoa_rounding3(
	char *integer,
	int *integer_len,
	int precision)
{
	int		i;
	int		round_flag;

	round_flag = integer[*integer_len + precision] >= 5;
	if (integer[*integer_len + precision] == 5)
	{
		i = *integer_len + precision;
		while (i < *integer_len && i > 0)
		{
			if (integer[i] != 0)
				break ;
			++i;
		}
		if (i == *integer_len && integer[precision - 2] % 2 != 0)
			round_flag = 0;
	}
	ft_dtoa_rounding2(integer, integer_len, round_flag, -precision);
}

static void	ft_dtoa_rounding(
	char *integer,
	char *decimal,
	int *integer_len,
	int precision)
{
	int		round_flag;
	char	tmp;

	precision -= *integer_len - 1;
	round_flag = ft_dtoa_ut_check_round((precision <= 0 ? \
	integer[*integer_len - 1] : decimal[precision - 1]), decimal, precision);
	if (round_flag && precision >= 0 && precision < FT_DBL_MAX_ARR)
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
			ft_dtoa_rounding2(integer, integer_len, round_flag, 0);
	}
	else if (round_flag)
		ft_dtoa_rounding2(integer, integer_len, round_flag, 0);
	else if (precision < 0)
		ft_dtoa_rounding3(integer, integer_len, precision);
}

char		*ft_dtoa_e_to_str2(
	char *decimal,
	int integer_len,
	int exp)
{
	int		i;
	char	*result;

	i = 0;
	if (exp >= 0 || exp == -1023)
	{
		result = ft_strdup(integer_len < 10 ? "+0" : "+");
		result = ft_strjoin_free_both(result, \
			ft_itoa(exp == -1023 ? 0 : integer_len - 1));
	}
	else
	{
		while (i < FT_DBL_MAX_ARR)
		{
			if (decimal[i++] != 0)
				break ;
		}
		result = ft_strdup(i < 10 ? "-0" : "-");
		result = ft_strjoin_free_both(result, ft_itoa(i));
	}
	return (result);
}

char		*ft_dtoa_e_to_str(
	char *integer,
	char *decimal,
	int integer_len,
	int precision)
{
	int		i;
	char	*result;

	if (!(result = malloc(sizeof(char) * (precision + (precision ? 4 : 3)))))
		return (0);
	i = 0;
	result[i++] = (integer_len ? integer[0] : decimal[0]) + '0';
	if (precision)
		result[i++] = '.';
	while (i < precision + (precision ? 2 : 1))
	{
		if (integer_len && i - 1 < integer_len)
			result[i] = integer[i - 1] + '0';
		else if (i - integer_len - 1 < FT_DBL_MAX_ARR)
			result[i] = decimal[i - integer_len - 1] + '0';
		else
			result[i] = '0';
		++i;
	}
	result[i++] = 'e';
	result[i] = 0;
	return (result);
}

char		*ft_dtoa_e(t_double n, int precision)
{
	char	integer[FT_DBL_INT_MAX_ARR];
	char	decimal[FT_DBL_MAX_ARR];
	char	*result;
	int		integer_len;

	integer_len = ft_dtoa_setup_integer(n, integer);
	ft_dtoa_setup_decimal(n, decimal);
	ft_dtoa_rounding(integer, decimal, &integer_len, precision);
	result = ft_dtoa_e_to_str(integer, decimal, integer_len, precision);
	if (n.sign)
		result = ft_strjoin_free_second("-", result);
	result = ft_strjoin_free_both(result, \
		ft_dtoa_e_to_str2(decimal, integer_len, n.exponent - (int)FT_DBL_BIAS));
	return (result);
}
