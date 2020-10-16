/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_out.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 18:14:49 by jaeskim           #+#    #+#             */
/*   Updated: 2020/10/16 15:56:52 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_util.h"

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
