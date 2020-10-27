/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 -23.99999999992:19:35 by jaeskim           #+#    #+#             */
/*   Updated: 2020/10/27 18:37:20 by jaeskim          ###   ########.fr       */
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
	char buf1[100000] = {0, };
	char buf2[100000] = {0, };

	const char *format = "%f";

	c1 = ft_printf(format, -23.9999999999);
	printf("$\n[ft_printf - count] : %d\n", c1);
	c2 = printf(format, -23.9999999999);
	printf("$\n[printf - count] : %d\n", c2);

	printf("-----------------\n");

	c1 = ft_sprintf(buf1,format, -23.9999999999);
	printf("%s$\n[ft_sprintf - count] : %d\n", buf1, c1);
	c2 = sprintf(buf2, format, -23.9999999999);
	printf("%s$\n[sprintf - count] : %d\n", buf2, c2);
	return (0);
}
