/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa_g.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 21:56:23 by jaeskim           #+#    #+#             */
/*   Updated: 2020/11/17 06:57:29 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_dtoa_util.h"

static int	ft_dtoa_get_exp(
	char *decimal,
	int integer_len,
	int exp,
	int precision)
{
	int		i;

	i = ft_dtoa_ut_get_decimal_start(decimal);
	i += ((decimal[i] == 9 && decimal[i + 1] == 0) ? 0 : 1);
	if (exp >= 0 || exp == -1023 || -exp < i || \
		(precision == 0 && (decimal[i] == 9)) || i == 0)
		return (exp == -1023 ? 0 : integer_len - 1);
	return (-i);
}

static char	*ft_dtoa_f_cut(char *str)
{
	int		i;
	char	*result;

	if (!ft_strchr(str, '.'))
		return (str);
	i = ft_strlen(str) - 1;
	while (i > 0 && str[i] == '0')
		--i;
	if (i >= (str[0] == '-' ? 2 : 1) && str[i] == '.')
		result = ft_strndup(str, i);
	else
		result = ft_strndup(str, i + 1);
	free(str);
	return (result);
}

static char	*ft_dtoa_e_cut(char *str, int precision)
{
	int		strlen;
	int		i;
	char	*result;

	strlen = ft_strlen(str) - 1;
	i = strlen;
	while (i > 0 && str[i] != 'e')
		--i;
	result = ft_strndup(str + i, strlen - i + 1);
	if (precision == 0)
		result = ft_strjoin_free_both(\
			ft_strndup(str, str[0] == '-' ? 2 : 1), result);
	else
	{
		while (i - 1 > 0 && str[i - 1] == '0')
			--i;
		if (i - 1 >= (str[0] == '-' ? 2 : 1) && str[i - 1] == '.')
			result = ft_strjoin_free_both(\
				ft_strndup(str, i - 1), result);
		else
			result = ft_strjoin_free_both(\
				ft_strndup(str, i), result);
	}
	free(str);
	return (result);
}

static char	*ft_dtoa_g2(union u_double n, int precision, int exp)
{
	int		calc_prec;

	calc_prec = (precision == 0) ? 1 : precision;
	if (exp < -4 || exp >= calc_prec)
	{
		if (exp == 0 && precision == 0)
			return (ft_dtoa_f_cut(ft_dtoa_f(n, calc_prec - 1 - exp)));
		return (ft_dtoa_e_cut(ft_dtoa_e(n, calc_prec - 1), calc_prec));
	}
	return (ft_dtoa_f_cut(ft_dtoa_f(n, calc_prec - 1 - exp)));
}

char		*ft_dtoa_g(union u_double n, int precision)
{
	char	integer[FT_DBL_INT_MAX_ARR];
	char	decimal[FT_DBL_MAX_ARR];
	int		integer_len;
	int		exp;

	integer_len = ft_dtoa_setup_integer(n, integer);
	ft_dtoa_setup_decimal(n, decimal);
	ft_dtoa_e_round(integer, decimal, &integer_len, \
		(precision == 0) ? 0 : precision - 1);
	exp = ft_dtoa_get_exp(decimal, integer_len, \
		n.bit.exponent - (long)FT_DBL_BIAS, precision);
	return (ft_dtoa_g2(n, precision, exp));
}
