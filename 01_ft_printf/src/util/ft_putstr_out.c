/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_out.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 18:15:21 by jaeskim           #+#    #+#             */
/*   Updated: 2020/10/14 18:46:04 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_util.h"

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
