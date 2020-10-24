/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 17:03:18 by jaeskim           #+#    #+#             */
/*   Updated: 2020/10/24 19:13:20 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_format(
	int cnt,
	t_format *pf)
{
	if (pf->flag.zero && !pf->flag.dash)
	{
		ft_putchar_n_out(pf->out, cnt - 1, '0');
		ft_putchar_out(pf->out, '%');
	}
	else if (!pf->flag.dash)
	{
		ft_putchar_n_out(pf->out, cnt - 1, ' ');
		ft_putchar_out(pf->out, '%');
	}
	else
	{
		ft_putchar_out(pf->out, '%');
		ft_putchar_n_out(pf->out, cnt - 1, ' ');
	}
}

int			ft_print_percent(t_format *pf)
{
	int		cnt;

	++(*pf->ptr);
	cnt = pf->width > 1 ? pf->width : 1;
	ft_print_format(cnt, pf);
	free(pf);
	return (cnt);
}
