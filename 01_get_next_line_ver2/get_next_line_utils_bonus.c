/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 17:49:10 by jaeskim           #+#    #+#             */
/*   Updated: 2021/02/02 01:10:00 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t len;

	len = 0;
	while (*s++)
		len++;
	return (len);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dp;
	const unsigned char	*sp;

	if (!dest && !src)
		return (0);
	dp = dest;
	sp = src;
	while (n-- > 0)
	{
		*dp++ = *sp++;
	}
	return (dest);
}

char	*ft_strjoin_free(char const *s1, char const *s2, int check)
{
	size_t	len1;
	size_t	len2;
	char	*result;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(result = (char *)malloc(sizeof(char) + (len1 + len2 + 1))))
		return (0);
	ft_memcpy(result, s1, len1);
	ft_memcpy(result + len1, s2, len2);
	result[len1 + len2] = '\0';
	if (check & 1)
		free((char *)s1);
	if (check & 2)
		free((char *)s2);
	return (result);
}

char	*ft_strndup(const char *s, size_t n)
{
	char	*result;

	if (!(result = (char *)malloc(sizeof(char) * (n + 1))))
		return (0);
	ft_memcpy(result, s, n);
	result[n] = '\0';
	return (result);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != c)
	{
		if (*s == '\0')
			return (0);
		s++;
	}
	return (char *)s;
}
