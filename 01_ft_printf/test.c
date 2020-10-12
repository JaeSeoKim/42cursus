/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 02:19:35 by jaeskim           #+#    #+#             */
/*   Updated: 2020/10/12 22:50:27 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	main(void)
{
	int c1;
	int c2;

	c1 = ft_printf("%dSeoul %c", 42, '!');
	printf("\n[ft_printf - count] : %d\n", c1);
	c2 = printf("%dSeoul %c", 42, '!');
	printf("\n[printf - count] : %d\n", c2);
	return (0);
}
