/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 06:21:07 by jaeskim           #+#    #+#             */
/*   Updated: 2020/09/25 08:26:06 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_memcmp - compare memory areas
*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *s1p;
	const unsigned char *s2p;

	s1p = (const unsigned char *)s1;
	s2p = (const unsigned char *)s2;
	while (n-- > 0)
	{
		if (*s1p != *s2p)
			return (*s1p - *s2p);
		s1p++;
		s2p++;
	}
	return (0);
}
