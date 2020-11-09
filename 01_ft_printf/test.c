/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 02:19:35 by jaeskim           #+#    #+#             */
/*   Updated: 2020/11/09 18:17:14 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
#include <unistd.h>
#include <wchar.h>
#include <locale.h>

static void	ft_dtoa_revers(int *a, int n)
{
	int tmp[(1023 + 52)];
	int i;

	ft_memmove(tmp, a, sizeof(int) * n);
	i = 0;
	while (i < n)
	{
		a[n - i - 1] = tmp[i];
		++i;
	}
}

static void	ft_dtoa_multiply(int *a, int num, int n)
{
	int	result[(1023 + 52)];
	int round;
	int i;

	ft_memset(result, 0, sizeof(int) * (1023 + 52));
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
	ft_memmove(a, result, sizeof(int) * n);
}

int main(void)
{
	t_double	n;
	int			decimal[(1023 + 52)];
	int			tmp[(1023 + 52)];
	long		significand;
	ft_memset(decimal, 0, sizeof(int) * (1023 + 52));
	ft_memset(tmp, 0, sizeof(int) * (1023 + 52));
	
	int i;
	int exp;
	
	n.d = 0;
	n.exponent = 0;
	n.mantissa = 1;
	i = 0;
	printf("mantissa: ");
	while (i < 52)
		printf("%d", (n.mantissa >> (51 - i++)) & 1 ? 1 : 0);
	printf("\n");

	exp = n.exponent - (long)FT_DBL_BIAS;
	printf("exp: %d\n", exp);
	if (exp > 0)
	{
		significand = n.mantissa << 12 << exp;
		significand >>= 12;
	}
	else
		significand = n.mantissa;
	decimal[0] = exp < 0 ? 1 : 0;
	i = 0;
	int j = exp < 0 ? -exp : 0;
	if (n.exponent == 0)
		j -= 1;
	printf("%d\n", j);
	while (i < 52)
	{
		decimal[j++] = (significand >> (51 - i)) & 1 ? 1 : 0;
		++i;
	}
	
	i = 0;
	while (i < (1023 + 52))
		printf("%d", decimal[i++]);
	printf("\n%.*f\n\n", 1023 + 51, n.d);
	i = 0;
	tmp[0] = 1;
	while (i < j)
	{
		ft_dtoa_multiply(tmp, 5, i + 1);
		++i;
	}
	
	i = 0;
	ft_dtoa_revers(tmp, 1023 + 52);
	while (i < (1023 + 52))
		printf("%d", tmp[i++]);

	printf("\n");
	ft_memset(tmp, 0, sizeof(int) * (1023 + 52));
	tmp[0] = 1;
	while (i < 10)
	{
		ft_dtoa_multiply(tmp, 5, i + 1);
		++i;
	}
	ft_dtoa_revers(tmp, 1023 + 52);
	while (i < (1023 + 52))
		printf("%d", tmp[i++]);
	return (0);
}


// int main(void)
// {
// 	// int c1;
// 	// int c2;
// 	// long long int lli;
// 	// char buf1[100000] = {0, };
// 	// char buf2[100000] = {0, };

// 	// const char *format = "%f123, n.d_asd";
// 	// c1 = ft_printf(format);
// 	// printf("$\n[ft_printf - count] : %d\n", c1);
// 	// c2 = printf(format);
// 	// printf("$\n[printf - count] : %d\n", c2);

// 	t_double n;
// 	long sum;
// 	long test;
// 	long tmp;
// 	sum = 0;
// 	n.d = 0.12312412412;

// 	test = 0;
// 	test |= 1;
// 	test <<= 64 + (n.exponent - (unsigned long)FT_DBL_BIAS);
	
// 	tmp = 0;
// 	tmp |= n.mantissa;
// 	tmp <<= 12 + (n.exponent - (unsigned long)FT_DBL_BIAS);
// 	tmp |= test;

// 	// for (int i = 0; i < 64; i++)
// 	// 	printf("%d", ((tmp >> (63 - i)) & 1) == 1);

// 	t_bigint *result;
// 	t_bigint *tmp_bigint;
// 	t_bigint *tmp_bigint2;

// 	result = ft_bigint_new(0);
// 	for (int i = 0; i < 64; i++)
// 	{
// 		tmp_bigint = ft_bigint_multiply(result, 10);
// 		result = tmp_bigint;
// 		if (((tmp >> (63 - i)) & 1) == 1)
// 		{
// 			tmp_bigint = ft_bigint_new(5);
// 			for (int j = 0; j < i; j++)
// 			{
// 				tmp_bigint2 = ft_bigint_multiply(tmp_bigint, 5);
// 				tmp_bigint = tmp_bigint2;
// 			}
// 			tmp_bigint2 = ft_bigint_add(result, tmp_bigint);
// 			result = tmp_bigint2;
// 		}
// 	}
// 	printf("\nBITTTTT: %s\n", ft_bigint_to_str(result));
// 	printf("%.64f\n", n.d);
// 	printf("exp : %d\n", (n.exponent - (unsigned long)FT_DBL_BIAS));

// 	// printf("\n%ld\n", test);
// 	// printf("pf\t%.50f\n", n.d);
// 	// printf("sign\t\t:%d\n", n.sign);
// 	// printf("exponent\t:%ld\n", (n.exponent - (long)FT_DBL_BIAS));
// 	// printf("mantissa\t:");
// 	// for (int i = 0; i < 52; i++)
// 	// 	printf("%d", ((n.mantissa >> (51 - i)) & 1) == 1);
// 	// printf("\n");
// 	// printf("-----------------\n");

// 	// c1 = ft_sprintf(buf1,format, 0.87650894255);
// 	// printf("%s$\n[ft_sprintf - count] : %d\n", buf1, c1);
// 	// c2 = sprintf(buf2, format, 0.87650894255);
// 	// printf("%s$\n[sprintf - count] : %d\n", buf2, c2);
// 	// return (0);
// }