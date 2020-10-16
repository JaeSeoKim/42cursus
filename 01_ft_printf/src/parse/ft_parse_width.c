/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 16:01:26 by jaeskim           #+#    #+#             */
/*   Updated: 2020/10/16 18:33:09 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_parse_width(
		char **out,
		char **format,
		va_list ap,
		t_format_specifier *pformat)
{
	int tmp_width;

	tmp_width = 0;
	if (**format == '*')
	{
		pformat->width = va_arg(ap, int);
		++(*format);
	}
	else
	{
		while (ft_isdigit(**format))
		{
			tmp_width *= 10;
			tmp_width += **format - '0';
			++(*format);
		}
		pformat->width = tmp_width;
	}
	return (ft_parse_check(out, format, ap, pformat));
}
