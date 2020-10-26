/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 17:03:18 by jaeskim           #+#    #+#             */
/*   Updated: 2020/10/26 15:57:42 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int	ft_calc_width(
	int len,
	t_format *pf)
{
	int result;

	result = (pf->visit_precision && len > pf->precision ? pf->precision : len);
	return (result);
}

static void	ft_print_precision(
	int len,
	t_format *pf,
	char *str)
{
	int i;

	i = 0;
	if (len > pf->precision && pf->visit_precision)
	{
		while (i < pf->precision)
		{
			ft_putchar_out(pf->out, str[i]);
			++i;
		}
	}
	else
		ft_putstr_out(pf->out, str);
}

static void	ft_print_format(
	int cnt,
	t_format *pf,
	char *str,
	int len)
{
	if (pf->flag.zero && !pf->flag.dash && !pf->visit_precision)
	{
		ft_putchar_n_out(pf->out, cnt - \
			ft_calc_width(len, pf), '0');
		ft_print_precision(len, pf, str);
	}
	else if (!pf->flag.dash)
	{
		ft_putchar_n_out(pf->out, cnt - \
			ft_calc_width(len, pf), ' ');
		ft_print_precision(len, pf, str);
	}
	else
	{
		ft_print_precision(len, pf, str);
		ft_putchar_n_out(pf->out, cnt - \
			ft_calc_width(len, pf), ' ');
	}
}

int			ft_print_string(va_list ap, t_format *pf)
{
	char	*str;
	int		cnt;
	int		len;

	++(*pf->ptr);
	str = ft_get_extend_s(ap, pf);
	len = ft_strlen(str);
	cnt = (pf->visit_precision && len > pf->precision) ? pf->precision : len;
	cnt = pf->width > cnt ? pf->width : cnt;
	ft_print_format(cnt, pf, str, len);
	ft_frees(2, str, pf);
	return (cnt);
}
