/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa_e.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 20:05:49 by jaeskim           #+#    #+#             */
/*   Updated: 2020/11/16 22:25:50 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_dtoa_util.h"

char		*ft_dtoa_e_to_str2(
	char *decimal,
	int integer_len,
	int exp,
	int precision)
{
	int		i;
	char	*result;

	i = ft_dtoa_ut_get_decimal_start(decimal);
	i += ((decimal[i] == 9 && decimal[i + 1] == 0) ? 0 : 1);
	if (exp >= 0 || exp == -1023 || -exp < i || \
		(precision == 0 && (decimal[i] == 9)) || i == 0)
	{
		result = ft_strdup((integer_len - 1) < 10 ? "+0" : "+");
		result = ft_strjoin_free_both(result, \
			ft_itoa(exp == -1023 ? 0 : integer_len - 1));
	}
	else
	{
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
	int		j;
	char	*result;

	if (!(result = malloc(sizeof(char) * (precision + (precision ? 4 : 3)))))
		return (0);
	i = 0;
	j = ft_dtoa_ut_get_decimal_start(decimal);
	result[i++] = (integer[0] != 0 ? integer[0] : decimal[j++]) + '0';
	if (precision)
		result[i++] = '.';
	while (i < precision + (precision ? 2 : 1))
	{
		if (integer_len && i - 1 < integer_len)
			result[i] = integer[i - 1] + '0';
		else if (integer[0] != 0)
			result[i] = (i - integer_len - 1) < FT_DBL_MAX_ARR ? \
				decimal[i - integer_len - 1] + '0' : '0';
		else
			result[i] = j < FT_DBL_MAX_ARR ? decimal[j++] + '0' : '0';
		++i;
	}
	result[i++] = 'e';
	result[i] = 0;
	return (result);
}

char		*ft_dtoa_e(union u_double n, int precision)
{
	char	integer[FT_DBL_INT_MAX_ARR];
	char	decimal[FT_DBL_MAX_ARR];
	char	*result;
	int		integer_len;

	integer_len = ft_dtoa_setup_integer(n, integer);
	ft_dtoa_setup_decimal(n, decimal);
	ft_dtoa_e_round(integer, decimal, &integer_len, precision);
	result = ft_dtoa_e_to_str(integer, decimal, integer_len, precision);
	if (n.bit.sign)
		result = ft_strjoin_free_second("-", result);
	result = ft_strjoin_free_both(result, \
		ft_dtoa_e_to_str2(decimal, integer_len, \
			n.bit.exponent - (int)FT_DBL_BIAS, precision));
	return (result);
}
