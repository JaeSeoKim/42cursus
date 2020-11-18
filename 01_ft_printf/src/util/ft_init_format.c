/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 18:15:58 by jaeskim           #+#    #+#             */
/*   Updated: 2020/11/19 01:35:27 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_util.h"

static void	ft_init_flag(t_flag *flag)
{
	flag->dash = 0;
	flag->zero = 0;
	flag->blank = 0;
	flag->plus = 0;
	flag->hash = 0;
}

t_format	*ft_init_format(char **out, char **format, int *cnt)
{
	t_format *result;

	if (!(result = malloc(sizeof(t_format))))
		return (0);
	ft_init_flag(&result->flag);
	result->visit_width = 0;
	result->width = 0;
	result->visit_precision = 0;
	result->precision = 0;
	result->h_count = 0;
	result->l_count = 0;
	result->out = out;
	result->ptr = format;
	result->cnt = cnt;
	return (result);
}
