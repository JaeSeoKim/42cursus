/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 20:17:14 by jaeskim           #+#    #+#             */
/*   Updated: 2020/11/15 16:30:59 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_substr - A new String containing the extracted characters
*/

char	*ft_substr(char const *s, uint32_t start, size_t len)
{
	char *result;

	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (!(result = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	ft_memcpy(result, s + start, len);
	result[len] = '\0';
	return (result);
}
