/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_print_sturct.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 16:56:55 by jaeskim           #+#    #+#             */
/*   Updated: 2020/10/18 22:22:25 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_test_print_sturct(
		char **format,
		t_format_specifier *pformat)
{
	printf("is_left		: %d\n", pformat->is_left);
	printf("is_zeropad	: %d\n", pformat->is_zeropad);
	printf("is_blank	: %d\n", pformat->is_blank);
	printf("is_plus		: %d\n", pformat->is_plus);
	printf("is_hash		: %d\n", pformat->is_hash);
	printf("width		: %d\n", pformat->width);
	printf("precision	: %d\n", pformat->precision);
	printf("h_count		: %d\n", pformat->h_count);
	printf("l_count		: %d\n", pformat->l_count);
	printf("type		: %c\n", **format);
}
