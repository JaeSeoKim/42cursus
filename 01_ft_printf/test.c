/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 02:19:35 by jaeskim           #+#    #+#             */
/*   Updated: 2020/10/23 21:18:54 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "ft_utf8.h"
#include <stdio.h>
#include <unistd.h>
#include <wchar.h>
#include <locale.h>

int main(void)
{
	setlocale(LC_ALL, "");

	int c1;
	int c2;
	char buf1[100000] = {0, };
	char buf2[100000] = {0, };

	const char *format = "%lc";

	c1 = ft_printf(format, L'☠');
	printf("$\n[ft_printf - count] : %d\n", c1);
	c2 = printf(format, L'☠');
	printf("$\n[printf - count] : %d\n", c2);

	printf("-----------------\n");

	c1 = ft_sprintf(buf1,format, L'☠');
	printf("%s$\n[ft_sprintf - count] : %d\n", buf1, c1);
	c2 = sprintf(buf2, format, L'☠');
	printf("%s$\n[sprintf - count] : %d\n", buf2, c2);
	return (0);
}
