/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 17:03:18 by jaeskim           #+#    #+#             */
/*   Updated: 2020/10/27 18:42:52 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static void	ft_print_format(
	int cnt,
	t_format *pf,
	char *n_str,
	int n_len)
{
	if (pf->flag.zero && !pf->flag.dash && !pf->visit_precision)
	{
		ft_putchar_n_out(pf->out, cnt - n_len, '0');
		ft_putstr_out(pf->out, n_str);
	}
	else if (!pf->flag.dash)
	{
		ft_putchar_n_out(pf->out, cnt - n_len, ' ');
		ft_putstr_out(pf->out, n_str);
	}
	else
	{
		ft_putstr_out(pf->out, n_str);
		ft_putchar_n_out(pf->out, cnt - n_len, ' ');
	}
}

int			ft_print_float(va_list ap, t_format *pf)
{
	long double	n;
	int			cnt;
	char		*tmp;
	char		*n_str;
	int			n_len;

	++(*pf->ptr);
	n = ft_get_extend_f(ap, pf);
	n_str = ft_dtoa(n, pf->visit_precision ? pf->precision : 6);
	if ((pf->flag.plus || pf->flag.blank) && n >= 0)
	{
		tmp = ft_strjoin(pf->flag.plus ? "+" : " ", n_str);
		free(n_str);
		n_str = tmp;
	}
	n_len = ft_strlen(n_str);
	cnt = pf->width > n_len ? pf->width : n_len;
	cnt = pf->precision > cnt ? pf->precision : cnt;
	ft_print_format(cnt, pf, n_str, n_len);
	ft_frees(2, n_str, pf);
	return (cnt);
}
