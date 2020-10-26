/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_frees.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 18:35:42 by jaeskim           #+#    #+#             */
/*   Updated: 2020/10/26 03:19:45 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_frees(int cnt, ...)
{
	va_list ap;

	va_start(ap, cnt);
	while (cnt)
	{
		free(va_arg(ap, void *));
		--cnt;
	}
	va_end(ap);
}
