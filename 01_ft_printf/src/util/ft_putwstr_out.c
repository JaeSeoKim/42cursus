/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr_out.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 18:15:21 by jaeskim           #+#    #+#             */
/*   Updated: 2020/10/21 18:06:41 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_util.h"

void	ft_putwstr_out(char **out, int *s)
{
	if (out)
	{
		while (*s)
		{
			**out = *s;
			++s;
			++(*out);
		}
	}
	else
	{
		while (*s)
		{
			ft_putchar_fd(*s, 1);
			++s;
		}
	}
}
