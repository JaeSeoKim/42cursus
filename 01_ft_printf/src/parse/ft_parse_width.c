/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 16:01:26 by jaeskim           #+#    #+#             */
/*   Updated: 2020/11/03 19:10:52 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_parse_width(va_list ap, t_format *pf)
{
	int		tmp_width;

	tmp_width = 0;
	pf->visit_width = 0;
	if (**(pf->ptr) == '*')
	{
		if ((pf->width = va_arg(ap, int)) < 0)
		{
			pf->width = -pf->width;
			pf->flag.dash = 1;
		}
		++(*pf->ptr);
	}
	else
	{
		while (ft_isdigit(**(pf->ptr)))
		{
			tmp_width *= 10;
			tmp_width += (**pf->ptr) - '0';
			++(*pf->ptr);
		}
		pf->width = tmp_width;
	}
	return (ft_parse_check(ap, pf));
}
