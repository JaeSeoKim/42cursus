/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 17:48:48 by jaeskim           #+#    #+#             */
/*   Updated: 2020/10/04 15:36:18 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	storejoin(char **store, char *buf, ssize_t read_size)
{
	char	*tmp;

	buf[read_size] = '\0';
	if (0 != *store)
	{
		tmp = ft_strjoin(*store, buf);
		free(*store);
	}
	else
		tmp = ft_strndup(buf, read_size);
	*store = tmp;
	if (ft_strchr(*store, '\n'))
		return (1);
	return (0);
}

static int	ft_check_line(char **store, char **line)
{
	char	*ptr;
	char	*tmp;

	if ((ptr = ft_strchr(*store, '\n')))
	{
		*line = ft_strndup(*store, ptr - *store);
		tmp = ft_strndup(ptr + 1, ft_strlen(ptr + 1));
		free(*store);
		*store = tmp;
		return (1);
	}
	else
	{
		*line = *store;
		*store = 0;
		return (0);
	}
}

int			get_next_line(int fd, char **line)
{
	static char	*store[OPEN_MAX];
	ssize_t		read_size;
	char		*buf;

	if (fd < 0 || fd >= OPEN_MAX || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while ((read_size = read(fd, buf, BUFFER_SIZE)) >= 0)
	{
		if (storejoin(&store[fd], buf, read_size) || read_size <= 0)
			break ;
	}
	free(buf);
	if (read_size < 0)
		return (-1);
	return (ft_check_line(&store[fd], line));
}
