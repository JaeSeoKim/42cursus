/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 17:03:18 by jaeskim           #+#    #+#             */
/*   Updated: 2020/11/14 20:07:29 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static char	*ft_custom_dtoa(long double n, t_format *pf, char spec)
{
	t_double	num;
	char		*tmp;
	char		*n_str;

	num.d = n;
	n_str = ft_dtoa(n, pf->visit_precision ? pf->precision : 6, spec);
	if (pf->visit_precision && pf->flag.hash && !pf->precision)
	{
		if (spec == 'f')
		{
			tmp = ft_strjoin_free_first(n_str, ".");
			n_str = tmp;
		}
		else
		{
			tmp = ft_strndup(n_str, num.sign ? 2 : 1);
			tmp = ft_strjoin_free_first(tmp, ".");
			n_str = ft_strjoin_free_both(tmp, \
				ft_strndup(n_str + (num.sign ? 2 : 1), \
				ft_strlen(n_str) - (num.sign ? 2 : 1)));
		}
	}
	return (n_str);
}

static int	ft_calc_width(
	t_double n,
	int n_len,
	t_format *pf)
{
	if (n.sign || pf->flag.plus || \
		(pf->flag.blank && !n.sign))
		++n_len;
	return (n_len);
}

static void	ft_print_flag(t_double n, t_format *pf)
{
	if (n.sign)
		ft_putchar_out(pf->out, '-');
	else if (pf->flag.plus)
		ft_putchar_out(pf->out, '+');
	else if (pf->flag.blank && !n.sign)
		ft_putchar_out(pf->out, ' ');
}

static void	ft_print_format(
	t_double n,
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
	t_double		n;
	int				cnt;
	char			*tmp;
	char			*n_str;
	int				n_len;

	n.d = va_arg(ap, double);
	if (n.exponent == FT_DBL_EXP_NAN)
		return (ft_print_float_nan(n, pf));
	n_str = ft_custom_dtoa(n.d, pf, **pf->ptr);
	++(*pf->ptr);
	if (n.sign)
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
