/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa_setup_decimal.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 22:47:17 by jaeskim           #+#    #+#             */
/*   Updated: 2020/11/09 22:01:45 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_dtoa_util.h"

static void	ft_dtoa_revers(int *a, int n)
{
	char	tmp[FT_DBL_MAX_ARR];
	int		i;

	ft_memmove(tmp, a, sizeof(char) * n);
	i = 0;
	while (i < n)
	{
		a[n - i - 1] = tmp[i] + '0';
		++i;
	}
}

static void ft_dtoa_add(int *a, int *b)
{
	
}

static void	ft_dtoa_multiply(int *a, int num, int n)
{
	char	result[FT_DBL_MAX_ARR];
	int		round;
	int		i;

	ft_memset(result, 0, sizeof(char) * FT_DBL_MAX_ARR);
	round = 0;
	i = 0;
	while (i < n)
	{
		result[i] = (a[i] * num) + (round % 10);
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
	i = 0;
	ft_memmove(a, result, sizeof(char) * n);
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
	j = exp < 0 ? -j : 0;
	if (n.exponent == 0 || exp >= 0)
		j -= 1;
	while (i < 52)
		decimal[j++] = (significand >> (51 - i++)) & 1 ? 1 : 0;
	i = 0;
	ft_memset(tmp_mul, 0, sizeof(char) * FT_DBL_MAX_ARR);
	tmp_mul[0] = 1;
	while (i < FT_DBL_MAX_ARR)
	{
		ft_dtoa_multiply(tmp_mul, 5, i + 1);
		if (decimal[i] == 1)
		{
			
		}
	}
}

void		ft_dtoa_setup_decimal(t_double n, char *decimal)
{
	int		exp;
	long	significand;

	ft_memset(decimal, 0, sizeof(char) * FT_DBL_MAX_ARR);
	exp = n.exponent - (int)FT_DBL_BIAS;
	decimal[0] = exp < 0 ? 1 : 0;
	if (exp > 0)
	{
		significand = n.mantissa << 12 << exp;
		significand >>= 12;
	}
	else
		significand = n.mantissa;
	ft_dtoa_setup_decimal2(n, decimal, significand, exp);
}
