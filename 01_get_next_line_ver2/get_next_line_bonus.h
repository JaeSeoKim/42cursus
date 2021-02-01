/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 17:49:05 by jaeskim           #+#    #+#             */
/*   Updated: 2021/02/02 01:05:00 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct	s_gnl
{
	int			fd;
	char		*line;
	void		*next;
}				t_gnl;

int				get_next_line(int fd, char **line);
size_t			ft_strlen(const char *s);
void			*ft_memcpy(void *dest, const void *src, size_t n);
char			*ft_strjoin_free(char const *s1, char const *s2, int check);
char			*ft_strndup(const char *s, size_t n);
char			*ft_strchr(const char *s, int c);

#endif
