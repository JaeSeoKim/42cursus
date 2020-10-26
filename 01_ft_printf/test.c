/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 02:19:35 by jaeskim           #+#    #+#             */
/*   Updated: 2020/10/26 16:20:19 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst_struct.h"
#include "ft_lst.h"
#include "ft_memory.h"
#include "ft_string.h"
#include "ft_type.h"
#include "ft_utf8.h"
#include "ft_write.h"
#include <stdio.h>
#include <unistd.h>
#include <wchar.h>
#include <locale.h>

int main(void)
{

	printf("%s\n", ft_convert_base_unsigned(1000, "0123456789", 10));
	// setlocale(LC_ALL, "");

	// int c1;
	// int c2;
	// long long int lli;
	// char buf1[100000] = {0, };
	// char buf2[100000] = {0, };

	// const char *format = "%0*.*X";

	// c1 = ft_printf(format, 1, 0, 0);
	// printf("$\n[ft_printf - count] : %d\n", c1);
	// c2 = printf(format, 1, 0, 0);
	// printf("$\n[printf - count] : %d\n", c2);

	// printf("-----------------\n");

	// c1 = ft_sprintf(buf1,format, 1, 0, 0);
	// printf("%s$\n[ft_sprintf - count] : %d\n", buf1, c1);
	// c2 = sprintf(buf2, format, 1, 0, 0);
	// printf("%s$\n[sprintf - count] : %d\n", buf2, c2);
	return (0);
}
