/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 17:03:18 by jaeskim           #+#    #+#             */
/*   Updated: 2020/11/17 05:48:51 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int	ft_calc_width(
	union u_double n,
	int n_len,
	t_format *pf)
{
	if (n.bit.sign || pf->flag.plus || \
		(pf->flag.blank && !n.bit.sign))
		++n_len;
	return (n_len);
}

static void	ft_print_flag(union u_double n, t_format *pf)
{
	if (n.bit.sign)
		ft_putchar_out(pf->out, '-');
	else if (pf->flag.plus)
		ft_putchar_out(pf->out, '+');
	else if (pf->flag.blank && !n.bit.sign)
		ft_putchar_out(pf->out, ' ');
}

static void	ft_print_format(
	union u_double n,
	int cnt,
	t_format *pf,
	char *n_str)
{
	if (pf->flag.zero && !pf->flag.dash)
	{
		ft_print_flag(n, pf);
		ft_putchar_n_out(pf->out, cnt - \
			ft_calc_width(n, ft_strlen(n_str), pf), '0');
		ft_putstr_out(pf->out, n_str);
	}
	else if (!pf->flag.dash)
	{
		ft_putchar_n_out(pf->out, cnt - \
			ft_calc_width(n, ft_strlen(n_str), pf), ' ');
		ft_print_flag(n, pf);
		ft_putstr_out(pf->out, n_str);
	}
	else
	{
		ft_print_flag(n, pf);
		ft_putstr_out(pf->out, n_str);
		ft_putchar_n_out(pf->out, cnt - \
			ft_calc_width(n, ft_strlen(n_str), pf), ' ');
	}
}

int			ft_print_float(va_list ap, t_format *pf)
{
	union u_double	n;
	int				cnt;
	char			*tmp;
	char			*n_str;
	int				n_len;

	n.d = va_arg(ap, double);
	if (n.bit.exponent == FT_DBL_EXP_NAN)
		return (ft_print_float_nan(n, pf));
	n_str = ft_custom_dtoa(n.d, pf, **pf->ptr);
	++(*pf->ptr);
	if (n.bit.sign)
	{
		tmp = ft_strdup(n_str + 1);
		free(n_str);
		n_str = tmp;
	}
	n_len = ft_calc_width(n, ft_strlen(n_str), pf);
	cnt = pf->width > n_len ? pf->width : n_len;
	ft_print_format(n, cnt, pf, n_str);
	ft_frees(2, n_str, pf);
	return (cnt);
}
