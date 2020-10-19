/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_extend_type.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 18:13:44 by jaeskim           #+#    #+#             */
/*   Updated: 2020/10/19 20:40:18 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_parse_extend_type(va_list ap, t_format *pf)
{
	char	**format;

	format = pf->ptr;
	if (**format == 'h')
		pf->h_count += 1;
	if (**format == 'l')
		pf->l_count += 1;

	++(*format);
	return (ft_parse_check(ap, pf));
}
