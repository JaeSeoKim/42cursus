/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 16:01:26 by jaeskim           #+#    #+#             */
/*   Updated: 2020/10/19 22:43:24 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_parse_width(va_list ap, t_format *pf)
{
	char	**format;
	int		tmp_width;

	format = pf->ptr;
	tmp_width = 0;
	pf->visit_width = 0;
	if (**format == '*')
	{
		pf->width = va_arg(ap, int);
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
		pf->width = tmp_width;
	}
	return (ft_parse_check(ap, pf));
}
