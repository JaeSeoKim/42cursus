/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 12:13:28 by jaeskim           #+#    #+#             */
/*   Updated: 2020/09/26 12:25:47 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_strdup - duplicate a string
*/

char	*ft_strdup(const char *s)
{
	size_t	slen;
	char	*result;

	slen = ft_strlen(s);
	if (!(result = (char *)malloc(sizeof(char) * (slen + 1))))
		return (0);
	slen = 0;
	while (s[slen])
	{
		result[slen] = s[slen];
		slen++;
	}
	result[slen] = '\0';
	return (result);
}
