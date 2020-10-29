/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 02:19:35 by jaeskim           #+#    #+#             */
/*   Updated: 2020/10/29 21:39:37 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
#include <unistd.h>
#include <wchar.h>
#include <locale.h>


#ifndef FT_DOUBLE_BIAS
# define FT_DOUBLE_BIAS 1023
#endif

union u_dtoa_test
{
	struct
	{
		unsigned long	frac	:52;
		unsigned long	exp		:11;
		unsigned long	sign	:1;
	};
	double	d;
};

static char	*ft_round_with_precision(
	double mantissa,
	int precision,
	long *exponent)
{
	int		i;
	long	tmp;
	char	*result;

	if (!(result = malloc(sizeof(char) * (precision + 1))))
		return (0);
	i = 0;
	while (i < precision)
	{
		mantissa *= 10;
		tmp = (long)mantissa;
		result[i++] = tmp + '0';
		mantissa -= tmp;
	}
	result[precision] = 0;
	return (result);
}



int main(void)
{

	ft_printf("%s\n", ft_round_with_precision(0.12340078, 5, NULL));
	// double				d;
	// long				num;
	// unsigned long		tmp;
	// union u_dtoa_test 	n;
	
	// n.d = -0.123;
	// printf("%d\t%f\n", sizeof(n), n.d);
	// printf("sign\t:%ld\n", n.sign);
	// printf("exp\t:%ld\n", (n.exp - (unsigned long)FT_DOUBLE_BIAS));
	// printf("frac\t:");
	// tmp = n.frac;
	// for (int i = 0; i < 52; i++)
	// {
	// 	printf("%d", ((tmp & 1) == 1));
	// 	tmp = tmp >> 1;
	// }
	// printf("\n");

	// printf("%d ", ((n.exp & 1024) == 1024));
	// printf("%d", ((n.exp & 512) == 512));
	// printf("%d", ((n.exp & 256) == 256));
	// printf("%d", ((n.exp & 128) == 128));
	// printf("%d ", ((n.exp & 64) == 64));
	// printf("%d", ((n.exp & 32) == 32));
	// printf("%d", ((n.exp & 16) == 16));
	// printf("%d", ((n.exp & 8) == 8));
	// printf("%d ", ((n.exp & 4) == 4));
	// printf("%d", ((n.exp & 2) == 2));
	// printf("%d\n", ((n.exp & 1) == 1));

	// num = n.sign ? -(long)n.d : (long)n.d;
	// d = n.d - num;
	// d = n.sign ? -d : d;
	// printf("%f\n", d);
	// n.d = d;
	// for (int i = 0; i < 100; i++)
	// {
	// 	tmp = (long)(n.d * 10);
	// 	printf("%d ", tmp);
	// 	n.d *= 10;
	// 	n.d -= tmp;
	// 	tmp = n.frac;
	// 	// printf("%f\n", n.d);
	// 	// for (int i = 0; i < 52; i++)
	// 	// {
	// 	// 	printf("%d", ((tmp & 1) == 1));
	// 	// 	tmp = tmp >> 1;
	// 	// }
	// 	printf("\n");
	// }
	
	
	return (0);
}
