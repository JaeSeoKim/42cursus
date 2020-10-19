/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_n_out.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 17:18:36 by jaeskim           #+#    #+#             */
/*   Updated: 2020/10/19 18:01:48 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_util.h"

void	ft_putchar_n_out(char **out, size_t n, char c)
{
	while (n-- > 0)
		ft_putchar_out(out, c);
}
