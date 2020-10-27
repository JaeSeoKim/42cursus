/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_octal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 17:03:18 by jaeskim           #+#    #+#             */
/*   Updated: 2020/10/28 05:11:03 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static void	ft_print_flag(t_format *pf, unsigned long long int n)
{
	if (pf->flag.hash && ((pf->visit_precision && \
		(pf->precision || n == 0)) || n != 0))
		ft_putchar_out(pf->out, '0');
}

static int	ft_calc_width(
	int n_len,
	t_format *pf,
	unsigned long long int n)
{
	int result;

	result = (pf->precision > n_len ? pf->precision : n_len);
	if (pf->precision <= n_len && \
		(pf->flag.hash && ((pf->visit_precision && \
			(pf->precision || n == 0)) || n != 0)))
		++result;
	return (result);
}

static void	ft_print_precision_with_num(
	int n_len,
	t_format *pf,
	char *n_str)
{
	int i;

	i = 0;
	if (n_len < pf->precision)
	{
		while (i < pf->precision - n_len - pf->flag.hash)
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
	char *n_str,
	unsigned long long int n)
{
	if (pf->flag.zero && !pf->flag.dash && !pf->visit_precision)
	{
		ft_print_flag(pf, n);
		ft_putchar_n_out(pf->out, cnt - \
			ft_calc_width(ft_strlen(n_str), pf, n), '0');
		ft_print_precision_with_num(ft_strlen(n_str), pf, n_str);
	}
	else if (!pf->flag.dash)
	{
		ft_putchar_n_out(pf->out, cnt - \
			ft_calc_width(ft_strlen(n_str), pf, n), ' ');
		ft_print_flag(pf, n);
		ft_print_precision_with_num(ft_strlen(n_str), pf, n_str);
	}
	else
	{
		ft_print_flag(pf, n);
		ft_print_precision_with_num(ft_strlen(n_str), pf, n_str);
		ft_putchar_n_out(pf->out, cnt - \
			ft_calc_width(ft_strlen(n_str), pf, n), ' ');
	}
}

int			ft_print_octal(va_list ap, t_format *pf)
{
	unsigned long long int	n;
	int						cnt;
	char					*n_str;
	int						n_len;

	++(*pf->ptr);
	n = ft_get_extend_u(ap, pf);
	n_str = ft_convert_base_custom(n, "012345678", 8, pf);
	n_len = ft_strlen(n_str);
	cnt = pf->width > n_len ? pf->width : n_len;
	cnt = pf->precision > cnt ? pf->precision : cnt;
	if (cnt == n_len && (pf->flag.hash && \
		((pf->visit_precision && pf->precision) || n != 0)))
		++cnt;
	ft_print_format(cnt, pf, n_str, n);
	ft_frees(2, n_str, pf);
	return (cnt);
}
