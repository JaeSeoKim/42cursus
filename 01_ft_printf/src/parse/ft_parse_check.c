/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 17:59:38 by jaeskim           #+#    #+#             */
/*   Updated: 2020/10/16 18:35:23 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_parse_check(
		char **out,
		char **format,
		va_list ap,
		t_format_specifier *pformat)
{
	if (ft_strchr("-0+# ", **format))
		return (ft_parse_flag(out, format, ap, pformat));
	if (ft_strchr("123456789*", **format))
		return (ft_parse_width(out, format, ap, pformat));
	if (ft_strchr(".", **format))
		return (ft_parse_precision(out, format, ap, pformat));
	if (ft_strchr("lh", **format))
		return (ft_parse_extend_type(out, format, ap, pformat));
	if (ft_strchr("cspdiuxXnfgeo%", **format))
		return (ft_parse_type(out, format, ap, pformat));

	free(pformat);
	return (-1);
}
