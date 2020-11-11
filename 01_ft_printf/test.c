/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 02:19:35 by jaeskim           #+#    #+#             */
/*   Updated: 2020/11/11 18:37:58 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "ft_dtoa_util.h"
#include <stdio.h>
#include <unistd.h>
#include <wchar.h>
#include <locale.h>
#include <limits.h>

// static void	ft_dtoa_revers(int *a, int n)
// {
// 	int tmp[(1023 + 52)];
// 	int i;

// 	ft_memmove(tmp, a, sizeof(int) * n);
// 	i = 0;
// 	while (i < n)
// 	{
// 		a[n - i - 1] = tmp[i];
// 		++i;
// 	}
// }

// static void	ft_dtoa_multiply(int *a, int num, int n)
// {
// 	int	result[(1023 + 52)];
// 	int round;
// 	int i;

// 	ft_memset(result, 0, sizeof(int) * (1023 + 52));
// 	round = 0;
// 	i = 0;
// 	while (i < n)
// 	{
// 		result[i] = (a[i] * num) + (round % 10);
// 		round = (round / 10) + (result[i] / 10);
// 		result[i] = (result[i] % 10);
// 		++i;
// 	}
// 	while (round)
// 	{

// 		result[i] = round % 10;
// 		round = (round / 10);
// 		++i;
// 	}
// 	i = 0;
// 	ft_memmove(a, result, sizeof(int) * n);
// }

// int main(void)
// {
// 	t_double	n;
// 	int			decimal[(1023 + 52)];
// 	int			tmp[(1023 + 52)];
// 	long		significand;
// 	ft_memset(decimal, 0, sizeof(int) * (1023 + 52));
// 	ft_memset(tmp, 0, sizeof(int) * (1023 + 52));
	
// 	int i;
// 	int exp;
	
// 	n.d = 0;
// 	n.exponent = 0;
// 	n.significand = 1;
// 	i = 0;
// 	printf("significand: ");
// 	while (i < 52)
// 		printf("%d", (n.significand >> (51 - i++)) & 1 ? 1 : 0);
// 	printf("\n");

// 	exp = n.exponent - (long)FT_DBL_BIAS;
// 	printf("exp: %d\n", exp);
// 	if (exp > 0)
// 	{
// 		significand = n.significand << 12 << exp;
// 		significand >>= 12;
// 	}
// 	else
// 		significand = n.significand;
// 	decimal[0] = exp < 0 ? 1 : 0;
// 	i = 0;
// 	int j = exp < 0 ? -exp : 0;
// 	if (n.exponent == 0)
// 		j -= 1;
// 	printf("%d\n", j);
// 	while (i < 52)
// 	{
// 		decimal[j++] = (significand >> (51 - i)) & 1 ? 1 : 0;
// 		++i;
// 	}
	
// 	i = 0;
// 	while (i < (1023 + 52))
// 		printf("%d", decimal[i++]);
// 	printf("\n%.*f\n\n", 1023 + 51, n.d);
// 	i = 0;
// 	tmp[0] = 1;
// 	while (i < j)
// 	{
// 		ft_dtoa_multiply(tmp, 5, i + 1);
// 		++i;
// 	}
	
// 	i = 0;
// 	ft_dtoa_revers(tmp, 1023 + 52);
// 	while (i < (1023 + 52))
// 		printf("%d", tmp[i++]);

// 	printf("\n");
// 	ft_memset(tmp, 0, sizeof(int) * (1023 + 52));
// 	tmp[0] = 1;
// 	while (i < 10)
// 	{
// 		ft_dtoa_multiply(tmp, 5, i + 1);
// 		++i;
// 	}
// 	ft_dtoa_revers(tmp, 1023 + 52);
// 	while (i < (1023 + 52))
// 		printf("%d", tmp[i++]);
// 	return (0);
// }


int main(void)
{
	int i;
	int exp;
	char	decimal[FT_DBL_MAX_ARR];
	char	integer[FT_DBL_INT_MAX_ARR];
	t_double n;

	n.d = 0.626;
	// exp =  n.exponent - (int)FT_DBL_BIAS;
	// for (int i = 0; i < 52; i++)
	// 	printf("%d", (n.significand >> (51 - i++)) & 1 ? 1 : 0);
	// printf("\n%d\n", exp);
	// ft_dtoa_setup_integer(n, integer);
	// printf("\n%f\n", n.d);
	ft_dtoa_setup_decimal(n, decimal);
	i = 0;
	while (i < FT_DBL_MAX_ARR)
		printf("%d", decimal[i++]);
	printf("\n%.*f\n", FT_DBL_MAX_ARR, n.d);
}