/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_custom_dtoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 05:48:39 by jaeskim           #+#    #+#             */
/*   Updated: 2020/11/17 06:27:37 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_dota_join_dot_e(union u_double num, char *n_str)
{
	char	*tmp;

	tmp = ft_strndup(n_str, num.bit.sign ? 2 : 1);
	tmp = ft_strjoin_free_first(tmp, ".");
	return (ft_strjoin_free_both(tmp, \
		ft_strndup(n_str + (num.bit.sign ? 2 : 1), \
		ft_strlen(n_str) - (num.bit.sign ? 2 : 1))));
}

static char	*ft_dota_join_dot_f(char *n_str)
{
	return (ft_strjoin_free_first(n_str, "."));
}

static char	*ft_dota_join_dot_g(union u_double num, char *n_str, int precision)
{
	int		i;
	int		j;
	int		tmp;
	char	*result;

	if (ft_strchr(n_str, 'e'))
	{
		result = ft_dota_join_dot_e(num, n_str);
		while (--precision > 0)
			result = ft_strjoin_free_first(result, "0");
		return (result);
	}
	result = ft_strchr(n_str, '.') ? n_str : ft_dota_join_dot_f(n_str);
	i = 0;
	tmp = ft_strlen(result);
	while (i < tmp && result[i] != '.')
		++i;
	j = 0;
	while (i + j < tmp && result[i + j])
		++j;
	while ((precision - (result[0] == '-' ? i - 1 : i) - j++ + 1) > 0)
		result = ft_strjoin_free_first(result, "0");
	return (result);
}

char		*ft_custom_dtoa(double n, t_format *pf, char spec)
{
	union u_double	num;
	char			*n_str;

	num.d = n;
	n_str = ft_dtoa(n, pf->visit_precision ? pf->precision : 6, spec);
	if (spec != 'g' && pf->visit_precision && pf->flag.hash && !pf->precision)
	{
		if (spec == 'f')
			n_str = ft_dota_join_dot_f(n_str);
		else if (spec == 'e')
			n_str = ft_dota_join_dot_e(num, n_str);
	}
	else if (spec == 'g' && pf->visit_precision && pf->flag.hash)
	{
		n_str = ft_dota_join_dot_g(num, n_str, pf->precision);
	}
	return (n_str);
}
