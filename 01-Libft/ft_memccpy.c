/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 21:09:22 by jaeskim           #+#    #+#             */
/*   Updated: 2020/09/25 00:50:35 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

/*
** ft_memccpy - copy memory area
*/

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*dp;
	const unsigned char	*sp;

	dp = dest;
	sp = src;
	while (n-- > 0)
	{
		if ((*dp++ = *sp++) == (unsigned char)c)
			return (dp);
	}
	return (0);
}
