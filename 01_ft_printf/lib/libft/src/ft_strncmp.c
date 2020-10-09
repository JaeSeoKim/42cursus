/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 09:18:57 by jaeskim           #+#    #+#             */
/*   Updated: 2020/09/26 09:55:10 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_strncmp - compare two strings
*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char u1;
	unsigned char u2;

	while (n-- > 0)
	{
		u1 = *(unsigned char *)s1++;
		u2 = *(unsigned char *)s2++;
		if (u1 != u2)
			return (u1 - u2);
		if (u1 == '\0')
			return (0);
	}
	return (0);
}
