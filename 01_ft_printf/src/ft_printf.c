/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 01:49:58 by jaeskim           #+#    #+#             */
/*   Updated: 2020/10/13 20:39:55 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_print_flag(char **out, char **format, va_list ap)
{
	if (**format == 'd' || **format == 'i')
		return (ft_print_int(out, format, ap));
	if (**format == 'c')
		return (ft_print_char(out, format, ap));
	return (-1);
}

static int	ft_print(char **out, const char *format, va_list ap)
{
	int		ctmp;
	int		count;
	char	*format_ptr;

	count = 0;
	format_ptr = (char *)format;
	while (*format_ptr)
	{
		if (*format_ptr == '%')
		{
			format_ptr++;
			if ((ctmp = ft_print_flag(out, &format_ptr, ap)) == -1)
				return (-1);
			count += ctmp;
		}
		else
		{
			ft_putchar_out(out, *format_ptr++);
			count++;
		}
	}
	return (count);
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, format);
	count = ft_print(0, format, ap);
	va_end(ap);
	return (count);
}

int			ft_sprintf(char *out, const char *format, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, format);
	count = ft_print(&out, format, ap);
	va_end(ap);
	return (count);
}
