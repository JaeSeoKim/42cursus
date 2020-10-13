/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 20:19:08 by jaeskim           #+#    #+#             */
/*   Updated: 2020/10/13 20:22:58 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putchar_out(char **out, char c)
{
	if (out)
	{
		**out = c;
		++(*out);
	}
	else
		ft_putchar_fd(c, 1);
}

void	ft_putstr_out(char **out, char *s)
{
	if (out)
	{
		while (*s)
		{
			**out = *s;
			++(*out);
			++s;
		}
	}
	else
		ft_putstr_fd(s, 1);
}
