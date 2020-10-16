/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 18:16:54 by jaeskim           #+#    #+#             */
/*   Updated: 2020/10/16 18:39:10 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

int		ft_parse_type(
		char **out,
		char **format,
		va_list ap,
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

	free(pformat);
	return (-1);
}
