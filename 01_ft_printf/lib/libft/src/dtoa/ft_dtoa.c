/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 21:15:58 by jaeskim           #+#    #+#             */
/*   Updated: 2020/11/10 14:54:39 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_dtoa_util.h"

char	*ft_dtoa(double n, int precision, char spec)
{
	t_double	num;

	num.d = n;
	if (num.exponent == FT_DBL_EXP_NAN)
	{
		if (num.significand == 0)
			return (ft_strdup(num.sign ? "-inf" : "inf"));
		return (ft_strdup("nan"));
	}
	if (spec == 'f')
		return (ft_dtoa_f(num, precision));
	if (spec == 'g')
		return (ft_dtoa_f(num, precision));
	if (spec == 'e')
		return (ft_dtoa_f(num, precision));
	return (0);
}
