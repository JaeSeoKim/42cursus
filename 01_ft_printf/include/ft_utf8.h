/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utf8.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 17:41:33 by jaeskim           #+#    #+#             */
/*   Updated: 2020/10/23 21:26:58 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTF8_H
# define FT_UTF8_H

# include <stdio.h>
# include "ft_printf.h"

# ifndef  UTF8_1
#  define UTF8_1 0x7F
# endif

# ifndef  UTF8_2
#  define UTF8_2 0x7FF
# endif

# ifndef  UTF8_3
#  define UTF8_3 0xFFFF
# endif

# ifndef UTF8_4
#  define UTF8_4 0x1FFFFF
# endif

void	ft_putwchar_fd(int unicode, int fd);
void	ft_putwchar_out(char **out, int unicode);
size_t	ft_wchar_len(int unicode);

#endif
