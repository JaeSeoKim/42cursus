/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 02:19:35 by jaeskim           #+#    #+#             */
/*   Updated: 2020/11/05 21:51:09 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
#include <unistd.h>
#include <wchar.h>
#include <locale.h>

int main(void)
{
	int c1;
	int c2;
	long long int lli;
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
	sum = 0;
	n.d = 0.1;

	// test = 0;
	// test |= 1;
	// test <<= 52;
	// test |= n.mantissa;

	// test >>= 52 - (n.exponent - (unsigned long)FT_DBL_BIAS);
	// for (int i = 0; i < 52; i++)
	// 	printf("%d", ((test >> (51 - i)) & 1) == 1);

	// printf("\n%ld\n", test);
	printf("pf\t%e\n", n.d);
	ft_printf("ft\t%e\n", n.d);
	printf("sign\t\t:%d\n", n.sign);
	printf("exponent\t:%ld\n", (n.exponent - (long)FT_DBL_BIAS));
	printf("mantissa\t:");
	for (int i = 0; i < 52; i++)
		printf("%d", ((n.mantissa >> (51 - i)) & 1) == 1);
	printf("\n");
	printf("-----------------\n");

	// c1 = ft_sprintf(buf1,format, 0.87650894255);
	// printf("%s$\n[ft_sprintf - count] : %d\n", buf1, c1);
	// c2 = sprintf(buf2, format, 0.87650894255);
	// printf("%s$\n[sprintf - count] : %d\n", buf2, c2);
	// return (0);
}
