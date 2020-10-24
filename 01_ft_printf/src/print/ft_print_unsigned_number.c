/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_number.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 17:03:18 by jaeskim           #+#    #+#             */
/*   Updated: 2020/10/24 17:23:38 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_calc_width(
	int n_len,
	t_format *pf)
{
	int result;

	result = (pf->precision > n_len ? pf->precision : n_len);
	return (result);
}

static void	ft_print_precision(
	int n_len,
	t_format *pf,
	char *n_str)
{
	int i;

	i = 0;
	if (n_len < pf->precision)
	{
		while (i < pf->precision - n_len)
		{
			ft_putchar_out(pf->out, '0');
			++i;
		}
	}
	ft_putstr_out(pf->out, n_str);
}

static void	ft_print_format(
	int cnt,
	t_format *pf,
	char *n_str)
{
	if (pf->flag.zero && !pf->flag.dash && !pf->precision)
	{
		ft_putchar_n_out(pf->out, cnt - \
			ft_calc_width(ft_strlen(n_str), pf), '0');
		ft_print_precision(ft_strlen(n_str), pf, n_str);
	}
	else if (!pf->flag.dash)
	{
		ft_putchar_n_out(pf->out, cnt - \
			ft_calc_width(ft_strlen(n_str), pf), ' ');
		ft_print_precision(ft_strlen(n_str), pf, n_str);
	}
	else
	{
		ft_print_precision(ft_strlen(n_str), pf, n_str);
		ft_putchar_n_out(pf->out, cnt - \
			ft_calc_width(ft_strlen(n_str), pf), ' ');
	}
}

int			ft_print_unsigned_number(va_list ap, t_format *pf)
{
	unsigned long long int	n;
	int						cnt;
	char					*n_str;
	int						n_len;

	++(*pf->ptr);
	n = ft_get_extend_u(ap, pf);
	n_str = ft_ullitoa(n, pf);
	n_len = ft_strlen(n_str);
	cnt = pf->width > n_len ? pf->width : n_len;
	cnt = pf->precision > cnt ? pf->precision : cnt;
	ft_print_format(cnt, pf, n_str);
	free(n_str);
	free(pf);
	return (cnt);
}
