/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa_setup_integer.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 17:47:36 by jaeskim           #+#    #+#             */
/*   Updated: 2020/11/13 18:17:47 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_dtoa_util.h"

static int	ft_dtoa_add(char *a, char *b, int b_len)
{
	char	result[FT_DBL_INT_MAX_ARR];
	int		round;
	int		i;

	ft_memset(result, 0, sizeof(char) * FT_DBL_INT_MAX_ARR);
	round = 0;
	i = 0;
	while (i < b_len)
	{
		result[i] = a[i] + b[i] + round;
		round = result[i] / 10;
		result[i] = result[i] % 10;
		i++;
	}
	if (round)
		result[i++] = round;
	ft_memmove(a, result, FT_DBL_INT_MAX_ARR);
	return (i);
}

static int	ft_dtoa_multiply(char *a, int n, int a_len)
{
	char	result[FT_DBL_INT_MAX_ARR];
	int		round;
	int		i;

	if (n == 0)
		return (1);
	ft_memset(result, 0, sizeof(char) * FT_DBL_INT_MAX_ARR);
	i = 0;
	round = 0;
	while (i < a_len)
	{
		result[i] = (a[i] * 2) + (round % 10);
		round = (round / 10) + (result[i] / 10);
		result[i] = (result[i] % 10);
		++i;
	}
	while (round)
	{
		result[i] = round % 10;
		round = (round / 10);
		++i;
	}
	ft_memmove(a, result, sizeof(char) * FT_DBL_INT_MAX_ARR);
	return (i);
}

static int	ft_dtoa_setup_integer3(
	char *bit,
	char *integer,
	int i)
{
	int		result_len;
	int		tmp_mul_len;
	char	result[FT_DBL_INT_MAX_ARR];
	char	tmp_mul[FT_DBL_INT_MAX_ARR];

	ft_memset(result, 0, sizeof(char) * FT_DBL_INT_MAX_ARR);
	ft_memset(tmp_mul, 0, sizeof(char) * FT_DBL_INT_MAX_ARR);
	i = FT_DBL_BIT_INT_MAX_ARR - 1;
	tmp_mul[0] = 1;
	result_len = 0;
	tmp_mul_len = 1;
	while (i >= 0)
	{
		tmp_mul_len = ft_dtoa_multiply(tmp_mul, \
			FT_DBL_BIT_INT_MAX_ARR - i - 1, tmp_mul_len);
		if (bit[i] == 1)
			result_len = ft_dtoa_add(result, tmp_mul, tmp_mul_len);
		--i;
	}
	ft_dta_ut_int_reverse(result, result_len);
	ft_memmove(integer, result, result_len);
	return (result_len);
}

static int	ft_dtoa_setup_integer2(
	char *integer,
	long significand,
	int exp)
{
	int		i;
	int		j;
	int		y;
	char	bit[FT_DBL_BIT_INT_MAX_ARR];

	ft_memset(bit, 0, sizeof(char) * FT_DBL_BIT_INT_MAX_ARR);
	i = 0;
	j = FT_DBL_BIT_INT_MAX_ARR - exp;
	y = (exp < 52) ? exp : 52;
	bit[j - 1] = 1;
	while (i < y)
		bit[j++] = (significand >> ((y - 1 - i++))) & 1 ? 1 : 0;
	return (ft_dtoa_setup_integer3(bit, integer, 0));
}

int			ft_dtoa_setup_integer(t_double n, char *integer)
{
	int		exp;
	long	significand;

	ft_memset(integer, 0, sizeof(char) * FT_DBL_INT_MAX_ARR);
	exp = n.exponent - (long)FT_DBL_BIAS;
	if (exp < 52)
		significand = n.significand >> (52 - exp);
	else
		significand = n.significand;
	if (exp < 0)
		return (1);
	return (ft_dtoa_setup_integer2(integer, significand, exp));
}
