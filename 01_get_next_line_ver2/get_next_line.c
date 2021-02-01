/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 17:48:48 by jaeskim           #+#    #+#             */
/*   Updated: 2021/02/02 01:13:44 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_gnl	*gnl_new(int fd)
{
	t_gnl	*result;

	if (!(result = malloc(sizeof(t_gnl))))
		return (0);
	result->fd = fd;
	result->line = 0;
	result->next = 0;
	return (result);
}

static t_gnl	*check_gnl(t_gnl **store, int fd)
{
	t_gnl	*ptr;

	if (!(*store))
		return ((*store) = gnl_new(fd));
	ptr = *store;
	while (ptr->next && ptr->fd != fd)
		ptr = ptr->next;
	if (ptr->fd == fd)
		return (ptr);
	return ((ptr->next) = gnl_new(fd));
}

static void		gnl_del(t_gnl **store, int fd)
{
	t_gnl	*prev;
	t_gnl	*now;

	if (!((*store)->next))
	{
		free(*store);
		*store = 0;
		return ;
	}
	prev = 0;
	now = *store;
	while (now->next && now->fd != fd)
	{
		prev = now;
		now = prev->next;
	}
	if (now->next)
		prev->next = now->next;
	else
		prev->next = 0;
	free(now);
}

static int		ft_check_line(t_gnl **store, t_gnl *gnl, char **line)
{
	char	*ptr;
	char	*tmp;

	if ((ptr = ft_strchr(gnl->line, '\n')))
	{
		*line = ft_strndup(gnl->line, ptr - gnl->line);
		tmp = ft_strndup(ptr + 1, ft_strlen(ptr + 1));
		free(gnl->line);
		gnl->line = tmp;
		return (1);
	}
	else
	{
		*line = gnl->line;
		gnl_del(store, gnl->fd);
		return (0);
	}
}

int				get_next_line(int fd, char **line)
{
	static t_gnl	*store;
	ssize_t			read_size;
	t_gnl			*ptr;
	char			buf[BUFFER_SIZE + 1];

	if (fd < 0 || !line || BUFFER_SIZE <= 0 || !(ptr = check_gnl(&store, fd)))
		return (-1);
	while ((read_size = read(fd, buf, BUFFER_SIZE)) >= 0)
	{
		buf[read_size] = 0;
		if (ptr->line)
			ptr->line = ft_strjoin_free(ptr->line, buf, 1);
		else
			ptr->line = ft_strndup(buf, read_size);
		if (ft_strchr(ptr->line, '\n') || read_size == 0)
			break ;
	}
	if (read_size < 0)
		return (-1);
	return (ft_check_line(&store, ptr, line));
}
