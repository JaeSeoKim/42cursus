/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 18:31:47 by jaeskim           #+#    #+#             */
/*   Updated: 2020/10/14 18:51:43 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_PARSE_H
# define FT_PRINT_PARSE_H

# include <stdarg.h>
# include "ft_printf_sturct.h"

int		ft_init_parsing(char **out, char **format, va_list ap);
int		ft_parse_flag(
			char **out,
			char **format,
			va_list ap,
			t_format_specifier *pformat);

#endif