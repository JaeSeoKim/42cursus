/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 21:15:58 by jaeskim           #+#    #+#             */
/*   Updated: 2020/11/03 11:19:08 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_dtoa(double n, int precision, char spec)
{
	t_double	num;

	num.d = n;

	if (num.exponent == FT_DBL_EXP_NAN)
	{
		if (num.mantissa == 0)
			return (ft_strdup(num.sign ? "-inf" : "inf"));
		return (ft_strdup(num.sign ? "-nan" : "nan"));
	}
	return (0);
}
