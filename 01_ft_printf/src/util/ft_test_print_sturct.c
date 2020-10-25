/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_print_sturct.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 16:56:55 by jaeskim           #+#    #+#             */
/*   Updated: 2020/10/25 16:53:35 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_test_print_sturct(t_format *pformat)
{
	printf("dash		: %d\n", pformat->flag.dash);
	printf("zero		: %d\n", pformat->flag.zero);
	printf("blank		: %d\n", pformat->flag.blank);
	printf("plus		: %d\n", pformat->flag.plus);
	printf("hash		: %d\n", pformat->flag.hash);
	printf("width		: %d\n", pformat->width);
	printf("precision	: %d\n", pformat->precision);
	printf("v_precision	: %d\n", pformat->visit_precision);
	printf("h_count		: %d\n", pformat->h_count);
	printf("l_count		: %d\n", pformat->l_count);
	printf("type		: %c\n", **pformat->ptr);
}
