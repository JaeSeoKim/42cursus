/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 16:13:40 by jaeskim           #+#    #+#             */
/*   Updated: 2020/10/14 18:35:08 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_int(char **format, va_list ap, char **result)
{
	int		count;
	char	*num;
	char	*tmp;

	(*format)++;
	num = ft_itoa(va_arg(ap, int));
	count = ft_strlen(num);
	tmp = ft_strjoin(*result, num);
	free(*result);
	*result = tmp;
	return (count);
}
