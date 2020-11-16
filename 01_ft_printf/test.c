/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 02:19:35 by jaeskim           #+#    #+#             */
/*   Updated: 2020/11/17 06:52:51 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
#include <unistd.h>
#include <wchar.h>
#include <locale.h>
#include <stddef.h>

int main(void)
{
	setlocale(LC_ALL, "");
	int c1;
	int c2;
	long long int lli;
	char buf1[100000] = {0, };
	char buf2[100000] = {0, };

	const char *format = "%.1g";
	union u_double n;

	n.d = -9.9;

	ft_printf("EXP : %d\n", n.bit.exponent - (long)FT_DBL_BIAS);

	c1 = ft_printf(format, n.d);
	printf("$\n[ft_printf - count] : %d\n", c1);
	c2 = printf(format, n.d);
	printf("$\n[printf - count] : %d\n", c2);

	// printf("-----------------\n");

	// c1 = ft_sprintf(buf1,format, -145125.5);
	// printf("%s$\n[ft_sprintf - count] : %d\n", buf1, c1);
	// c2 = sprintf(buf2, format, -145125.5);
	// printf("%s$\n[sprintf - count] : %d\n", buf2, c2);
	return (0);
}
