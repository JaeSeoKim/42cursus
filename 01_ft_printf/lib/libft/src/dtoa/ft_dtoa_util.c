/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 21:15:58 by jaeskim           #+#    #+#             */
/*   Updated: 2020/11/11 22:43:19 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dta_ut_int_reverse(char *a, int a_len)
{
	char	result[FT_DBL_INT_MAX_ARR];
	int		i;

	ft_memset(result, 0, sizeof(char) * FT_DBL_INT_MAX_ARR);
	i = a_len;
	while (i-- > 0)
		result[a_len - 1 - i] = a[i];
	ft_memmove(a, result, FT_DBL_INT_MAX_ARR);
}

int		ft_dtoa_ut_check_round(int c, char *decimal, int precision)
{
	int		i;

	i = precision + 1;
	while (i < FT_DBL_MAX_ARR)
	{
		if (decimal[i++] != 0)
			break ;
	}
	if (i == FT_DBL_MAX_ARR)
	{
		if (c % 2 == 0)
			return ((decimal[precision] > 5) ? 1 : 0);
	}
	return ((decimal[precision] >= 5) ? 1 : 0);
}
