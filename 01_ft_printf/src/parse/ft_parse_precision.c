/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 18:11:38 by jaeskim           #+#    #+#             */
/*   Updated: 2020/10/21 18:54:44 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_parse_precision(va_list ap, t_format *pf)
{
	char	**format;
	int		tmp_precision;

	format = pf->ptr;
	tmp_precision = 0;
	pf->visit_precision = 1;
	++(*format);
	if (**format == '*')
	{
		if ((pf->precision = va_arg(ap, int) < 0))
			pf->visit_precision = 0;
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
		pf->precision = tmp_precision;
	}
	return (ft_parse_check(ap, pf));
}
