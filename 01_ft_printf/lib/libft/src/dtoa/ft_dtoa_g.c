/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa_g.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 21:56:23 by jaeskim           #+#    #+#             */
/*   Updated: 2020/11/15 16:31:20 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_dtoa_util.h"

char		*ft_dtoa_f(t_double n, int precision)
{
	char	integer[FT_DBL_INT_MAX_ARR];
	char	decimal[FT_DBL_MAX_ARR];
	char	*result;
	int		integer_len;

	integer_len = ft_dtoa_setup_integer(n, integer);
	ft_dtoa_setup_decimal(n, decimal);
	ft_dtoa_rounding(integer, decimal, &integer_len, precision);
	result = ft_dtoa_int_to_str(integer, integer_len, \
		n.exponent - (long)FT_DBL_BIAS);
	if (n.sign)
		result = ft_strjoin_free_second("-", result);
	if (precision == 0)
		return (result);
	result = ft_strjoin_free_first(result, ".");
	result = ft_strjoin_free_both(result, \
		ft_dtoa_decimal_to_str(decimal, precision));
	return (result);
}
