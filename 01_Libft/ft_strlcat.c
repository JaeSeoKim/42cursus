/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 22:01:48 by jaeskim           #+#    #+#             */
/*   Updated: 2020/09/30 19:42:16 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_strlcat - size-bounded string copying and concatenation
*/

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t destlen;
	size_t srclen;

	srclen = ft_strlen(src);
	if ((destlen = ft_strlen(dest)) > size)
		destlen = size;
	if (destlen == size)
		return (size + srclen);
	if (srclen < size - destlen)
	{
		ft_memcpy(dest + destlen, src, srclen);
		dest[destlen + srclen] = '\0';
	}
	else
	{
		ft_memcpy(dest + destlen, src, size - destlen - 1);
		dest[size - 1] = '\0';
	}
	return (destlen + srclen);
}
