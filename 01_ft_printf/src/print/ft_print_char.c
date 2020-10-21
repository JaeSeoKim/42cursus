/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 17:03:18 by jaeskim           #+#    #+#             */
/*   Updated: 2020/10/21 15:01:03 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_format(
	int cnt,
	t_format *pf,
	wint_t c,
	int len)
{
	if (pf->flag.zero && !pf->flag.dash)
	{
		ft_putchar_n_out(pf->out, cnt - len, '0');
		ft_putchar_out(pf->out, c);
	}
	else if (!pf->flag.dash)
	{
		ft_putchar_n_out(pf->out, cnt - len, ' ');
		ft_putchar_out(pf->out, c);
	}
	else
	{
		ft_putchar_out(pf->out, c);
		ft_putchar_n_out(pf->out, cnt - len, ' ');
	}
}

int			ft_print_char(va_list ap, t_format *pf)
{
	wint_t	c;
	int		cnt;
	int		len;

	++(*pf->ptr);
	c = ft_get_extend_c(ap, pf);
	if (c > 255)
		return (-1);
	len = (c / 255) + 1;
	cnt = pf->width > len ? pf->width : len;
	cnt = pf->precision > cnt ? pf->precision : cnt;
	ft_print_format(cnt, pf, c, len);
	return (cnt);
}
