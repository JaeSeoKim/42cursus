/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 01:49:58 by jaeskim           #+#    #+#             */
/*   Updated: 2020/10/11 19:29:32 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_parsing_flag(char **format, va_list ap)
{
	int		count;
	char	tmp;
	char	*buf;

	count = 0;
	if (ft_strncmp(*format, "c", 1) == 0)
	{
		tmp = va_arg(ap, int);
		write(1, &tmp, 1);
		count++;
		(*format)++;
	}
	else if (ft_strncmp(*format, "d", 1) == 0 ||
			ft_strncmp(*format, "i", 1) == 0)
	{
		buf = ft_itoa(va_arg(ap, int));
		count = ft_strlen(buf);
		write(1, buf, count);
		(*format)++;
	}
	return (count);
}

static int	ft_parsing(const char *format, va_list ap)
{
	int		count;
	char	*format_;

	count = 0;
	format_ = (char *)format;
	while (*format_)
	{
		if (*format_ == '%')
		{
			format_++;
			count += ft_parsing_flag(&format_, ap);
		}
		else
		{
			write(1, format_++, 1);
			count++;
		}
	}
	return (count);
}

int			ft_printf(const char *format, ...)
{
	va_list ap;
	int		count;

	va_start(ap, format);
	count = ft_parsing(format, ap);
	va_end(ap);
	return (count);
}
