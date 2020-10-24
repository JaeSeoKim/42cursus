/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_cnt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 16:57:43 by jaeskim           #+#    #+#             */
/*   Updated: 2020/10/24 17:24:00 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"

int			ft_write_cnt(va_list ap, t_format *pf)
{
	++(*pf->ptr);
	if (pf->l_count == 1)
		*(va_arg(ap, long int *)) = *(pf->cnt);
	else if (pf->l_count >= 2)
		*(va_arg(ap, long long int *)) = *(pf->cnt);
	else if (pf->h_count == 1)
		*(va_arg(ap, short int*)) = *(pf->cnt);
	else if (pf->h_count >= 2)
		*(va_arg(ap, signed char *)) = *(pf->cnt);
	else
		*(va_arg(ap, int *)) = *(pf->cnt);
	free(pf);
	return (0);
}
