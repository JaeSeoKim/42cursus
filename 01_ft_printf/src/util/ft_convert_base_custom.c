/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base_custom.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 19:56:00 by jaeskim           #+#    #+#             */
/*   Updated: 2020/10/26 15:57:47 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

char	*ft_convert_base_custom(
	unsigned long long int num,
	const char *base_set,
	int base,
	t_format *pf)
{
	if (num == 0 && pf->precision == 0 && pf->visit_precision == 1)
		return (ft_strdup(""));
	else
		return (ft_convert_base_unsigned(num, base_set, base));
}
