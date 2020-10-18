/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 01:49:19 by jaeskim           #+#    #+#             */
/*   Updated: 2020/10/18 17:31:21 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include "libft.h"
# include "ft_printf_util.h"
# include "ft_printf_sturct.h"
# include "ft_printf_parse.h"
# include "ft_print.h"

int		ft_printf(const char *format, ...);
int		ft_sprintf(char *out, const char *format, ...);

int		ft_print(char **out, const char *format, va_list ap);

#endif