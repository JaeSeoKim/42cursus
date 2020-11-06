/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 02:19:35 by jaeskim           #+#    #+#             */
/*   Updated: 2020/11/06 20:28:06 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
#include <unistd.h>
#include <wchar.h>
#include <locale.h>

int main(void)
{
	// int c1;
	// int c2;
	// long long int lli;
	// char buf1[100000] = {0, };
	// char buf2[100000] = {0, };

	// const char *format = "%f123, n.d_asd";
	// c1 = ft_printf(format);
	// printf("$\n[ft_printf - count] : %d\n", c1);
	// c2 = printf(format);
	// printf("$\n[printf - count] : %d\n", c2);

	t_double n;
	long sum;
	long test;
	long tmp;
	sum = 0;
	n.d = 0.464655646546;

	test = 0;
	test |= 1;
	test <<= 64 + (n.exponent - (unsigned long)FT_DBL_BIAS);
	
	tmp = 0;
	tmp |= n.mantissa;
	tmp <<= 12 + (n.exponent - (unsigned long)FT_DBL_BIAS);
	tmp |= test;

	// for (int i = 0; i < 64; i++)
	// 	printf("%d", ((tmp >> (63 - i)) & 1) == 1);

	t_bigint *result;
	t_bigint *tmp_bigint;
	t_bigint *tmp_bigint2;

	result = ft_bigint_new(0);
	for (int i = 0; i < 64; i++)
	{
		tmp_bigint = ft_bigint_multiply(result, 10);
		result = tmp_bigint;
		printf("\nmulty10: %s\n", ft_bigint_to_str(result));
		if (((tmp >> (63 - i)) & 1) == 1)
		{
			tmp_bigint = ft_bigint_new(5);
			for (int j = 0; j < i; j++)
			{
				tmp_bigint2 = ft_bigint_multiply(tmp_bigint, 5);
				tmp_bigint = tmp_bigint2;
			}
			printf("\n????: %s\n", ft_bigint_to_str(tmp_bigint));
			tmp_bigint2 = ft_bigint_add(result, tmp_bigint);
			result = tmp_bigint2;
		}
		printf("\nADD: %s\n", ft_bigint_to_str(result));
	}
	printf("\nBITTTTT: %s\n", ft_bigint_to_str(result));
	printf("%.64f\n", n.d);
	printf("exp : %d\n", (n.exponent - (unsigned long)FT_DBL_BIAS));

	// printf("\n%ld\n", test);
	// printf("pf\t%.50f\n", n.d);
	// printf("sign\t\t:%d\n", n.sign);
	// printf("exponent\t:%ld\n", (n.exponent - (long)FT_DBL_BIAS));
	// printf("mantissa\t:");
	// for (int i = 0; i < 52; i++)
	// 	printf("%d", ((n.mantissa >> (51 - i)) & 1) == 1);
	// printf("\n");
	// printf("-----------------\n");

	// c1 = ft_sprintf(buf1,format, 0.87650894255);
	// printf("%s$\n[ft_sprintf - count] : %d\n", buf1, c1);
	// c2 = sprintf(buf2, format, 0.87650894255);
	// printf("%s$\n[sprintf - count] : %d\n", buf2, c2);
	// return (0);
}
