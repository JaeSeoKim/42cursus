/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar_out.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 19:30:02 by jaeskim           #+#    #+#             */
/*   Updated: 2020/10/23 21:27:58 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utf8.h"

static void	ft_utf_4(int unicode, char **out)
{
	**out = (unicode >> 18 & 7) | 240;
	++(*out);
	**out = (unicode >> 12 & 63) | 128;
	++(*out);
	**out = (unicode >> 6 & 63) | 128;
	++(*out);
	**out = (unicode & 63) | 128;
	++(*out);
}

static void	ft_utf_3(int unicode, char **out)
{
	**out = (unicode >> 12 & 15) | 224;
	++(*out);
	**out = (unicode >> 6 & 63) | 128;
	++(*out);
	**out = (unicode & 63) | 128;
	++(*out);
}

static void	ft_utf_2(int unicode, char **out)
{
	**out = unicode >> 6 | 192;
	++(*out);
	**out = (unicode & 63) | 128;
	++(*out);
}

static void	ft_utf_1(char unicode, char **out)
{
	**out = unicode;
	++(*out);
}

void		ft_putwchar_out(char **out, int unicode)
{
	if (out)
	{
		if ((unicode | UTF8_1) == UTF8_1)
			ft_utf_1(unicode, out);
		else if ((unicode | UTF8_2) == UTF8_2)
			ft_utf_2(unicode, out);
		else if ((unicode | UTF8_3) == UTF8_3)
			ft_utf_3(unicode, out);
		else if ((unicode | UTF8_4) == UTF8_4)
			ft_utf_4(unicode, out);
		else
			ft_putchar_out(out, unicode);
	}
	else
		ft_putwchar_fd(unicode, 1);
}
