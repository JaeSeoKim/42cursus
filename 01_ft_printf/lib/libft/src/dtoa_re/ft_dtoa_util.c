/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 21:15:58 by jaeskim           #+#    #+#             */
/*   Updated: 2020/11/08 18:25:05 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_dtoa_ut_itoa(long integer, int sign)
{
	char			*tmp;
	char			*result;

	if (!sign)
		return (ft_convert_base_unsigned(integer, "0123456789", 10));
	tmp = ft_convert_base_unsigned(integer, "0123456789", 10);
	result = ft_strjoin("-", tmp);
	free(tmp);
	return (result);
}

int		ft_dtoa_ut_check_round(t_double n, int c, long integer, int precision)
{
	if (precision > 16)
		return (0);
	if ((n.mantissa << \
		((precision + 1 + (n.exponent - FT_DBL_BIAS))) << 12) == 0)
	{
		if (integer % 2 == 0)
			return (c > 5);
	}
	return (c >= 5);
}
