/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 18:16:54 by jaeskim           #+#    #+#             */
/*   Updated: 2020/10/24 19:11:40 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

int		ft_parse_type(va_list ap, t_format *pf)
{
	if (**pf->ptr == 'd' || **pf->ptr == 'i')
		return (ft_print_number(ap, pf));
	if (**pf->ptr == 'u')
		return (ft_print_unsigned_number(ap, pf));
	if (**pf->ptr == 'c')
		return (ft_print_char(ap, pf));
	if (**pf->ptr == 's')
		return (ft_print_string(ap, pf));
	if (**pf->ptr == 'n')
		return (ft_write_cnt(ap, pf));
	if (**pf->ptr == '%')
		return (ft_print_percent(pf));
	free(pf);
	return (-1);
}
