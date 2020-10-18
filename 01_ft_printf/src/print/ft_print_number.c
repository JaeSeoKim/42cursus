/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 17:03:18 by jaeskim           #+#    #+#             */
/*   Updated: 2020/10/18 22:21:38 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_flag(
	char **out,
	long long int n,
	t_format_specifier *pformat)
{
	if (n < 0)
	{
		ft_putchar_out(out, '-');
		return (1);
	}
	if (pformat->is_plus)
	{
		ft_putchar_out(out, '+');
		return (1);
	}
	return (0);
}

static void	ft_print_precision(
	char **out,
	char **format,
	size_t value_len,
	int precision)
{
	int i;

	if (value_len > precision)
		return ;
	i = 0;
	while (i < precision - value_len)
	{
		ft_putchar_out(out, '0');
		++i;
	}
}

static void	ft_print_width(
	char **out,
	char **format,
	size_t value_len,
	t_format_specifier *pformat)
{
	int i;

	if (pformat->width <= value_len || pformat->width <= pformat->precision)
		return ;
	i = 0;
	while (i < pformat->width - \
		(value_len <= pformat->precision ? pformat->precision : value_len))
	{
		if (pformat->is_zeropad && !pformat->precision)
			ft_putchar_out(out, '0');
		else
			ft_putchar_out(out, ' ');
		++i;
	}
}

int			ft_print_number(
	char **out,
	char **format,
	va_list ap,
	t_format_specifier *pformat)
{
	int		n;
	char	*str;
	size_t	str_len;

	++(*format);
	n = va_arg(ap, int);
	str = ft_ullitoa(n < 0 ? -(long long int)n : n);
	str_len = ft_strlen(str);

	if (pformat->is_zeropad && !pformat->is_left)
		ft_print_precision(out, format, str_len, \
			pformat->width - ft_print_flag(out, n, pformat));
	ft_putstr_out(out, str);
	free(str);
	return (0);
}
