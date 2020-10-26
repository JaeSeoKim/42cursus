/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_print_sturct.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 16:56:55 by jaeskim           #+#    #+#             */
/*   Updated: 2020/10/26 03:36:35 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// 이 함수는 나중에 삭제 되어야 함!


#include "ft_printf.h"

void	ft_test_print_sturct(t_format *pformat)
{
	ft_printf("dash			: %d\n", pformat->flag.dash);
	ft_printf("zero			: %d\n", pformat->flag.zero);
	ft_printf("blank		: %d\n", pformat->flag.blank);
	ft_printf("plus			: %d\n", pformat->flag.plus);
	ft_printf("hash			: %d\n", pformat->flag.hash);
	ft_printf("width		: %d\n", pformat->width);
	ft_printf("precision	: %d\n", pformat->precision);
	ft_printf("v_precision	: %d\n", pformat->visit_precision);
	ft_printf("h_count		: %d\n", pformat->h_count);
	ft_printf("l_count		: %d\n", pformat->l_count);
	ft_printf("type			: %c\n", **pformat->ptr);
}
