/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_format_specifier.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 18:15:58 by jaeskim           #+#    #+#             */
/*   Updated: 2020/10/16 15:59:26 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_util.h"

t_format_specifier	*ft_init_format_specifier(void)
{
	t_format_specifier *result;

	if (!(result = malloc(sizeof(t_format_specifier))))
		return (0);
	result->is_left = 0;
	result->is_zeropad = 0;
	result->is_blank = 0;
	result->is_plus = 0;
	result->is_hash = 0;
	result->width = 0;
	result->precision = 0;
	result->h_count = 0;
	result->l_count = 0;
	return (result);
}
