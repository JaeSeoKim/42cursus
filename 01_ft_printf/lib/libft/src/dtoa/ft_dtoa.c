/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 21:15:58 by jaeskim           #+#    #+#             */
/*   Updated: 2020/11/17 05:28:53 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_dtoa_util.h"

char	*ft_dtoa(double n, int precision, char spec)
{
	union u_double	num;

	num.d = n;
	if (num.bit.exponent == FT_DBL_EXP_NAN)
	{
		if (num.bit.significand == 0)
			return (ft_strdup(num.bit.sign ? "-inf" : "inf"));
		return (ft_strdup("nan"));
	}
	if (spec == 'g')
		return (ft_dtoa_g(num, precision));
	if (spec == 'e')
		return (ft_dtoa_e(num, precision));
	return (ft_dtoa_f(num, precision));
}
