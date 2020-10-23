/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 17:46:22 by jaeskim           #+#    #+#             */
/*   Updated: 2020/10/23 21:27:57 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_utf8.h"

static void	ft_utf_4(int unicode, int fd)
{
	unsigned char buf;

	buf = (unicode >> 18 & 7) | 240;
	write(fd, &buf, 1);
	buf = (unicode >> 12 & 63) | 128;
	write(fd, &buf, 1);
	buf = (unicode >> 6 & 63) | 128;
	write(fd, &buf, 1);
	buf = (unicode & 63) | 128;
	write(fd, &buf, 1);
}

static void	ft_utf_3(int unicode, int fd)
{
	unsigned char buf;

	buf = (unicode >> 12 & 15) | 224;
	write(fd, &buf, 1);
	buf = (unicode >> 6 & 63) | 128;
	write(fd, &buf, 1);
	buf = (unicode & 63) | 128;
	write(fd, &buf, 1);
}

static void	ft_utf_2(int unicode, int fd)
{
	unsigned char buf;

	buf = unicode >> 6 | 192;
	write(fd, &buf, 1);
	buf = (unicode & 63) | 128;
	write(fd, &buf, 1);
}

static void	ft_utf_1(char unicode, int fd)
{
	write(fd, &unicode, 1);
}

void		ft_putwchar_fd(int unicode, int fd)
{
	if ((unicode | UTF8_1) == UTF8_1)
		ft_utf_1(unicode, fd);
	else if ((unicode | UTF8_2) == UTF8_2)
		ft_utf_2(unicode, fd);
	else if ((unicode | UTF8_3) == UTF8_3)
		ft_utf_3(unicode, fd);
	else if ((unicode | UTF8_4) == UTF8_4)
		ft_utf_4(unicode, fd);
	else
		ft_putchar_fd(unicode, fd);
}
