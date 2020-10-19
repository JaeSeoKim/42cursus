/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 18:16:54 by jaeskim           #+#    #+#             */
/*   Updated: 2020/10/19 22:28:39 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

int		ft_parse_type(va_list ap, t_format *pf)
{
	char	**format;

	format = pf->ptr;
	// ft_test_print_sturct(pf);
	if (**format == 'd' || **format == 'i')
		return (ft_print_number(ap, pf));
	free(pf);
	return (-1);
}
