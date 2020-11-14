/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa_e_round.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 20:05:49 by jaeskim           #+#    #+#             */
/*   Updated: 2020/11/14 21:30:28 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_dtoa_util.h"

static void	ft_dtoa_e_round2(
	char *integer,
	int *int_len,
	int round_flag,
	int i)
{
	char	tmp;

	ft_dta_ut_int_reverse(integer, *int_len);
	while (round_flag && i < *int_len)
	{
		if (!((tmp = integer[i] + round_flag) >= 10))
			round_flag = 0;
		integer[i] = tmp >= 10 ? 0 : tmp;
		++i;
	}
	if (round_flag && i < FT_DBL_INT_MAX_ARR)
	{
		++integer[i];
		++(*int_len);
	}
	ft_dta_ut_int_reverse(integer, *int_len);
}

static void	ft_dtoa_e_round3(
	char *integer,
	int *int_len,
	int prec)
{
	int		i;
	int		round_flag;

	round_flag = integer[*int_len + prec] >= 5;
	if (integer[*int_len + prec] == 5)
	{
		i = *int_len + prec;
		while (i < *int_len && i > 0)
		{
			if (integer[i] != 0)
				break ;
			++i;
		}
		if (i == *int_len && integer[prec - 2] % 2 != 0)
			round_flag = 0;
	}
	ft_dtoa_e_round2(integer, int_len, round_flag, -prec);
}

void		ft_dtoa_e_round(
	char *integer,
	char *dec,
	int *int_len,
	int prec)
{
	int		i;
	int		round_flag;
	char	tmp;

	prec -= *int_len - 1;
	round_flag = ft_dtoa_ut_check_round((prec <= 0 ? integer[*int_len - 1] : \
		dec[prec - 1]), dec, prec, integer[0] == 0);
	i = integer[0] == 0 ? (ft_dtoa_ut_get_decimal_start(dec) + 1) : 0;
	if (round_flag && prec >= 0 && prec < FT_DBL_MAX_ARR)
	{
		while (round_flag && (prec-- + i) > 0)
		{
			if (!((tmp = dec[prec + i] + round_flag) >= 10))
				round_flag = 0;
			dec[prec + i] = tmp >= 10 ? 0 : tmp;
		}
		if (prec >= 0 && round_flag)
			dec[prec] = 1;
		else if (round_flag)
			ft_dtoa_e_round2(integer, int_len, round_flag, 0);
	}
	else if (round_flag)
		ft_dtoa_e_round2(integer, int_len, round_flag, 0);
	else if (prec < 0)
		ft_dtoa_e_round3(integer, int_len, prec);
}
