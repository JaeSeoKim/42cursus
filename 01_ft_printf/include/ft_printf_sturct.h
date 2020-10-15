/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_sturct.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 18:03:58 by jaeskim           #+#    #+#             */
/*   Updated: 2020/10/15 16:21:54 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_STRUCT_H
# define FT_PRINTF_STRUCT_H

typedef struct	s_format_specifier
{
	int		is_left;
	int		is_zeropad;
	int		is_blank;
	int		is_Plus;
	int		is_hash;
	int		width;
	int		precision;
	int		h_count;
	int		l_count;
}				t_format_specifier;

#endif
