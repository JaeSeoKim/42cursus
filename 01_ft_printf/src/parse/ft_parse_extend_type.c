/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_extend_type.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 18:13:44 by jaeskim           #+#    #+#             */
/*   Updated: 2020/10/16 18:14:58 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_parse_extend_type(
		char **out,
		char **format,
		va_list ap,
		t_format_specifier *pformat)
{
	if (**format == 'h')
		pformat->h_count += 1;
	if (**format == 'l')
		pformat->l_count += 1;

	++(*format);
	return (ft_parse_check(out, format, ap, pformat));
}
