/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa_setup_decimal.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 22:47:17 by jaeskim           #+#    #+#             */
/*   Updated: 2020/11/12 17:12:46 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_dtoa_util.h"

static void	ft_dtoa_add(char *a, char *b)
{
	char	result[FT_DBL_MAX_ARR];
	int		round_flag;
	int		i;

	ft_memset(result, 0, sizeof(char) * FT_DBL_MAX_ARR);
	round_flag = 0;
	i = FT_DBL_MAX_ARR;
	while (i-- > 0)
	{
		result[i] = a[i] + b[i] + round_flag;
		round_flag = result[i] / 10;
		result[i] = result[i] % 10;
	}
	ft_memmove(a, result, FT_DBL_MAX_ARR);
}

static void	ft_dtoa_multiply(char *a, int n)
{
	char	result[FT_DBL_MAX_ARR];
	int		round;

	if (n == 0)
		return ;
	ft_memset(result, 0, sizeof(char) * FT_DBL_MAX_ARR);
	round = 0;
	while (n >= 0)
	{
		result[n + 1] = (a[n] * 5) + (round % 10);
		round = (round / 10) + (result[n + 1] / 10);
		result[n + 1] = (result[n + 1] % 10);
		--n;
	}
	result[0] = round;
	ft_memmove(a, result, sizeof(char) * FT_DBL_MAX_ARR);
}

static void	ft_dtoa_setup_decimal2(
	t_double n,
	char *decimal,
	long significand,
	int exp)
{
	int		i;
	int		j;
	char	result[FT_DBL_MAX_ARR];
	char	tmp_mul[FT_DBL_MAX_ARR];

	i = 0;
	j = exp < 0 ? -exp : 0;
	if (n.exponent == 0)
		j -= 1;
	else if (exp < 0)
		decimal[j - 1] = 1;
	while (i < 52)
		decimal[j++] = (significand >> (51 - i++)) & 1 ? 1 : 0;
	ft_memset(tmp_mul, 0, sizeof(char) * FT_DBL_MAX_ARR);
	ft_memset(result, 0, sizeof(char) * FT_DBL_MAX_ARR);
	i = 0;
	tmp_mul[0] = 5;
	while (i < j)
	{
		ft_dtoa_multiply(tmp_mul, i);
		if (decimal[i] == 1)
			ft_dtoa_add(result, tmp_mul);
		++i;
	}
	ft_memmove(decimal, result, sizeof(char) * i);
}

void		ft_dtoa_setup_decimal(t_double n, char *decimal)
{
	int		exp;
	long	significand;

	ft_memset(decimal, 0, sizeof(char) * FT_DBL_MAX_ARR);
	exp = n.exponent - (long)FT_DBL_BIAS;
	significand = exp > 0 ? n.significand << exp : n.significand;
	if (exp > 52)
		return ;
	ft_dtoa_setup_decimal2(n, decimal, significand, exp);
}
