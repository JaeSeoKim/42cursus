/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 18:47:21 by jaeskim           #+#    #+#             */
/*   Updated: 2020/10/14 22:54:19 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse_flag(
		char **out,
		char **format,
		va_list ap,
		t_format_specifier *pformat)
{
	if (**format == '-')
	{
		pformat->isleft = 1;
		++(*format);
	}

	// if ()
	return (-1);
}
