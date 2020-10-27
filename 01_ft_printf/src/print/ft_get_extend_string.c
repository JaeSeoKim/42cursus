/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_extend_string.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 22:07:13 by jaeskim           #+#    #+#             */
/*   Updated: 2020/10/28 03:03:14 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

wint_t	ft_get_extend_c(va_list ap, t_format *pf)
{
	if (pf->l_count == 1)
		return (wint_t)(va_arg(ap, int));
	return (char)(va_arg(ap, int));
}

char	*ft_get_extend_s(va_list ap, t_format *pf)
{
	char *tmp;

	if (pf->l_count == 1)
	{
		return (ft_n_encoding_utf8(va_arg(ap, wchar_t *), \
			pf->visit_precision ? pf->precision : -5));
	}
	tmp = va_arg(ap, char *);
	return (ft_strdup(tmp ? tmp : "(null)"));
}
