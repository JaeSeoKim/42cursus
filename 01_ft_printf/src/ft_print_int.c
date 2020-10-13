/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 16:13:40 by jaeskim           #+#    #+#             */
/*   Updated: 2020/10/13 20:27:42 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_int(char **out, char **format, va_list ap)
{
	int		count;
	char	*num;

	++(*format);
	num = ft_itoa(va_arg(ap, int));
	count = ft_strlen(num);
	ft_putstr_out(out, num);
	return (count);
}
