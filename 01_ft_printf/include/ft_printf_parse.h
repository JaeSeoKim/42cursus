/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 18:31:47 by jaeskim           #+#    #+#             */
/*   Updated: 2020/11/15 16:35:55 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_PARSE_H
# define FT_PRINTF_PARSE_H

# include <stdarg.h>
# include "libft.h"
# include "ft_printf_type.h"

int		ft_init_parsing(char **out, char **format, va_list ap, int *cnt);
int		ft_parse_check(va_list ap, t_format *pf);
int		ft_parse_flag(va_list ap, t_format *pf);
int		ft_parse_width(va_list ap, t_format *pf);
int		ft_parse_precision(va_list ap, t_format *pf);
int		ft_parse_extend_type(va_list ap, t_format *pf);
int		ft_parse_type(va_list ap, t_format *pf);

#endif
