/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 18:16:54 by jaeskim           #+#    #+#             */
/*   Updated: 2020/11/03 18:28:52 by jaeskim          ###   ########.fr       */
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
	if (**pf->ptr == 'o')
		return (ft_print_octal(ap, pf));
	if (**pf->ptr == 'x' || **pf->ptr == 'X')
		return (ft_print_hex(ap, pf));
	if (**pf->ptr == 'p')
		return (ft_print_pointer(ap, pf));
	if (**pf->ptr == 'f' || **pf->ptr == 'e' || **pf->ptr == 'g')
		return (ft_print_float(ap, pf));
	free(pf);
	return (-1);
}
