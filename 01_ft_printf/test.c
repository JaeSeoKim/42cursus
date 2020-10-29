/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 02:19:35 by jaeskim           #+#    #+#             */
/*   Updated: 2020/10/29 22:09:59 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
#include <unistd.h>
#include <wchar.h>
#include <locale.h>

union u_dtoa_d
{
	float	f;
	double	d;
	long double	ld;
	char	c[16];
};


int main(void)
{
	setlocale(LC_ALL, "");
	// union u_dtoa_d n;

	// n.f = 1.0;

	// printf("%e\n", n.f);
	// for(int i = 3; i >= 0; i--)
	// {
	// 	printf("%d", (n.c[i] & 128) ==128);
	// 	printf("%d", (n.c[i] & 64) == 64);
	// 	printf("%d", (n.c[i] & 32) == 32);
	// 	printf("%d ", (n.c[i] & 16) == 16);
	// 	printf("%d", (n.c[i] & 8) == 8);
	// 	printf("%d", (n.c[i] & 4) == 4);
	// 	printf("%d", (n.c[i] & 2) == 2);
	// 	printf("%d  ", (n.c[i] & 1) == 1);
	// 	if ((i) % 4 == 0)
	// 		printf("\n");
	// }
	int c1;
	int c2;
	long long int lli;
	char buf1[100000] = {0, };
	char buf2[100000] = {0, };

	const char *format = "%.10f";
	c1 = ft_printf(format, 0.87650894255);
	printf("$\n[ft_printf - count] : %d\n", c1);
	c2 = printf(format, 0.87650894255);
	printf("$\n[printf - count] : %d\n", c2);

	// printf("-----------------\n");

	// c1 = ft_sprintf(buf1,format, 0.87650894255);
	// printf("%s$\n[ft_sprintf - count] : %d\n", buf1, c1);
	// c2 = sprintf(buf2, format, 0.87650894255);
	// printf("%s$\n[sprintf - count] : %d\n", buf2, c2);
	// return (0);
}
