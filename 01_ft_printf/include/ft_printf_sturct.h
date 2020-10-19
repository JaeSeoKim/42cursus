/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_sturct.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 18:03:58 by jaeskim           #+#    #+#             */
/*   Updated: 2020/10/19 20:37:48 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_STRUCT_H
# define FT_PRINTF_STRUCT_H

# include "stdarg.h"
typedef struct	s_flag
{
	char	dash;
	char	zero;
	char	blank;
	char	plus;
	char	hash;
}				t_flag;

typedef struct	s_format
{
	t_flag	flag;
	int		width;
	int		precision;
	int		h_count;
	int		l_count;
	char	**out;
	char	**ptr;
}				t_format;

#endif
