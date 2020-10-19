/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 17:03:18 by jaeskim           #+#    #+#             */
/*   Updated: 2020/10/19 19:20:09 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_count(
	long long int n,
	size_t n_len,
	t_format_specifier *pf)
{
	int cnt;

	cnt = pf->width > n_len ? pf->width : n_len;
	cnt = pf->precision > cnt ? pf->precision : cnt;
	if ((cnt == pf->precision || cnt == n_len) &&
		(n < 0 || pf->is_plus || pf->is_blank))
		++cnt;
	return (cnt);
}

static int	ft_print_flag(
	char **out,
	long long int n,
	t_format_specifier *pf)
{
	if (n < 0)
	{
		ft_putchar_out(out, '-');
		return (1);
	}
	if (pf->is_plus)
	{
		ft_putchar_out(out, '+');
		return (1);
	}
	if (pf->is_blank && n >= 0)
	{
		ft_putchar_out(out, ' ');
		return (1);
	}
	return (0);
}

static int	ft_calc_width(
	long long n,
	size_t n_len,
	t_format_specifier *pf)
{
	int result;

	result = (pf->precision > n_len ? pf->precision : n_len);
	if (n < 0 || pf->is_plus || (pf->is_blank && n >= 0))
		++result;
	return (result);
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

int			ft_print_number(
	char **out,
	char **format,
	va_list ap,
	t_format_specifier *pf)
{
	int		n;
	int		cnt;
	char	*num_str;
	size_t	n_len;

	++(*format);
	n = va_arg(ap, int);
	num_str = ft_ullitoa(n < 0 ? -(long long int)n : n);
	n_len = ft_strlen(num_str);
	cnt = ft_check_count(n, n_len, pf);
	if (pf->is_zeropad && !pf->is_left && !pf->precision)
	{
		ft_print_precision(out, format, n_len,
			pf->width - ft_print_flag(out, n, pf));
		ft_putstr_out(out, num_str);
	}
	else if (!pf->is_left)
	{
		ft_putchar_n_out(out, cnt - ft_calc_width(n, n_len, pf), ' ');
		ft_print_flag(out, n, pf);
		ft_print_precision(out, format, n_len, pf->precision);
		ft_putstr_out(out, num_str);
	}
	else
	{
		ft_print_flag(out, n, pf);
		ft_print_precision(out, format, n_len, pf->precision);
		ft_putstr_out(out, num_str);
		ft_putchar_n_out(out, cnt - ft_calc_width(n, n_len, pf), ' ');
	}
	free(num_str);
	return (cnt);
}
