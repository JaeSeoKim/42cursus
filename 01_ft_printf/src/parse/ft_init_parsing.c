/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 18:27:47 by jaeskim           #+#    #+#             */
/*   Updated: 2020/10/19 20:19:00 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_init_parsing(char **out, char **format, va_list ap)
{
	t_format *pf;

	if (!(pf = ft_init_format(out, format)))
		return (-1);

	return (ft_parse_check(ap, pf));
}
