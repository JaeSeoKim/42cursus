/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_encoding_utf8_char.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 22:21:12 by jaeskim           #+#    #+#             */
/*   Updated: 2020/10/28 05:39:08 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_utf_4(int unicode)
{
	char *buf;

	buf = malloc(sizeof(char) * (4 + 1));
	buf[0] = (unicode >> 18 & 7) | 240;
	buf[1] = (unicode >> 12 & 63) | 128;
	buf[2] = (unicode >> 6 & 63) | 128;
	buf[3] = (unicode & 63) | 128;
	buf[4] = 0;
	return (buf);
}

static char	*ft_utf_3(int unicode)
{
	char *buf;

	buf = malloc(sizeof(char) * (3 + 1));
	buf[0] = (unicode >> 12 & 15) | 224;
	buf[1] = (unicode >> 6 & 63) | 128;
	buf[2] = (unicode & 63) | 128;
	buf[3] = 0;
	return (buf);
}

static char	*ft_utf_2(int unicode)
{
	char *buf;

	buf = malloc(sizeof(char) * (2 + 1));
	buf[0] = unicode >> 6 | 192;
	buf[1] = (unicode & 63) | 128;
	buf[2] = 0;
	return (buf);
}

static char	*ft_utf_1(int unicode)
{
	char *buf;

	buf = malloc(sizeof(char) * (1 + 1));
	buf[0] = unicode;
	buf[1] = 0;
	return (buf);
}

char		*ft_encoding_utf8_char(wchar_t unicode)
{
	if (!unicode)
		return (ft_strdup("(null)"));
	if ((unicode | UTF8_1) == UTF8_1)
		return (ft_utf_1(unicode));
	if ((unicode | UTF8_2) == UTF8_2)
		return (ft_utf_2(unicode));
	if ((unicode | UTF8_3) == UTF8_3)
		return (ft_utf_3(unicode));
	if ((unicode | UTF8_4) == UTF8_4)
		return (ft_utf_4(unicode));
	return (ft_utf_1(unicode));
}
