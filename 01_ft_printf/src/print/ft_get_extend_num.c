/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_extend_num.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 22:07:13 by jaeskim           #+#    #+#             */
/*   Updated: 2020/10/19 22:51:00 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long int	ft_get_extend_id(va_list ap, t_format *pf)
{
	signed char	tmp;

	if (pf->l_count == 1)
		return (va_arg(ap, long int));
	if (pf->l_count >= 2)
		return (va_arg(ap, long long int));
	if (pf->h_count == 1)
		return (short int)(va_arg(ap, int));
	if (pf->h_count >= 2)
		return (signed char)(va_arg(ap, int));
	return (va_arg(ap, int));
}
