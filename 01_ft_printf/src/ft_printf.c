/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 01:49:58 by jaeskim           #+#    #+#             */
/*   Updated: 2020/10/12 22:50:19 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_parsing_flag(char **format, va_list ap, char **result)
{
	if (ft_strncmp(*format, "c", 1) == 0)
	{
		*result = ft_str_add_char_with_free(*result, va_arg(ap, int));
		(*format)++;
		return (1);
	}
	if (**format == 'd' || **format == 'i')
		return (ft_format_int(format, ap, result));
	return (0);
}

static int	ft_parsing(const char *format, va_list ap, char **result)
{
	int		count;
	char	*format_ptr;

	count = 0;
	format_ptr = (char *)format;
	while (*format_ptr)
	{
		if (*format_ptr == '%')
		{
			format_ptr++;
			count += ft_parsing_flag(&format_ptr, ap, result);
		}
		else
		{
			*result = ft_str_add_char_with_free(*result, *format_ptr);
			format_ptr++;
			count++;
		}
	}
	return (count);
}

int			ft_printf(const char *format, ...)
{
	va_list ap;
	int		count;
	char	*result;

	va_start(ap, format);
	result = 0;
	count = ft_parsing(format, ap, &result);
	va_end(ap);
	write(1, result, count);
	return (count);
}
