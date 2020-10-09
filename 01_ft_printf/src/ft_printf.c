/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 01:49:58 by jaeskim           #+#    #+#             */
/*   Updated: 2020/10/10 05:02:36 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "stdarg.h"

int	ft_printf(const char *format, ...)
{
	va_list ap;

	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			if (*(format + 1) == 'd')
			{
				ft_putnbr_fd(va_arg(ap, int), 1);
				format+=2;
			}
			else if (*(format + 1) == 'c')
			{
				ft_putchar_fd(va_arg(ap, int), 1);
				format+=2;
			}
		}
		ft_putchar_fd(*format++, 1);
	}
	va_end(ap);
	return (0);
}

