/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 21:19:57 by jaeskim           #+#    #+#             */
/*   Updated: 2020/10/26 03:46:50 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wchar_len(int unicode)
{
	if ((unicode | UTF8_1) == UTF8_1)
		return (1);
	else if ((unicode | UTF8_2) == UTF8_2)
		return (2);
	else if ((unicode | UTF8_3) == UTF8_3)
		return (3);
	else if ((unicode | UTF8_4) == UTF8_4)
		return (4);
	return (1);
}
