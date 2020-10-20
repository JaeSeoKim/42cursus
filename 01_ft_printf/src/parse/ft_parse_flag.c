/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 18:47:21 by jaeskim           #+#    #+#             */
/*   Updated: 2020/10/20 23:38:21 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse_flag(va_list ap, t_format *pf)
{
	char **format;

	format = pf->ptr;
	if (**format == '-')
		pf->flag.dash = 1;
	if (**format == '0')
		pf->flag.zero = 1;
	if (**format == ' ')
		pf->flag.blank = 1;
	if (**format == '+')
		pf->flag.plus = 1;
	if (**format == '#')
		pf->flag.hash = 1;
	++(*format);
	return (ft_parse_check(ap, pf));
}
