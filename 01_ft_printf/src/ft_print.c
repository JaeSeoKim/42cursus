/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 18:24:57 by jaeskim           #+#    #+#             */
/*   Updated: 2020/11/03 19:08:30 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print(char **out, const char *format, va_list ap)
{
	int		ctmp;
	int		cnt;
	char	*format_ptr;

	cnt = 0;
	format_ptr = (char *)format;
	while (*format_ptr)
	{
		if (*format_ptr == '%')
		{
			format_ptr++;
			if ((ctmp = ft_init_parsing(out, &format_ptr, ap, &cnt)) == -1)
				return (-1);
			cnt += ctmp;
		}
		else
		{
			ft_putchar_out(out, *format_ptr++);
			cnt++;
		}
	}
	return (cnt);
}
