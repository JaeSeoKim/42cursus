/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 18:11:38 by jaeskim           #+#    #+#             */
/*   Updated: 2020/10/16 18:34:56 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_parse_precision(
		char **out,
		char **format,
		va_list ap,
		t_format_specifier *pformat)
{
	int tmp_precision;

	tmp_precision = 0;
	++(*format);
	if (**format == '*')
	{
		pformat->precision = va_arg(ap, int);
		++(*format);
	}
	else
	{
		while (ft_isdigit(**format))
		{
			tmp_precision *= 10;
			tmp_precision += **format - '0';
			++(*format);
		}
		pformat->precision = tmp_precision;
	}
	return (ft_parse_check(out, format, ap, pformat));
}
