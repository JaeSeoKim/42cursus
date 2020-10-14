/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 18:05:46 by jaeskim           #+#    #+#             */
/*   Updated: 2020/10/14 18:45:46 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF_UTIL_H
# define FT_PRINTF_UTIL_H

# include <stdarg.h>
# include "libft.h"
# include "ft_printf_sturct.h"

int					ft_print_int(char **out, char **format, va_list ap);
int					ft_print_char(char **out, char **format, va_list ap);

void				ft_putchar_out(char **out, char c);
void				ft_putstr_out(char **out, char *s);

t_format_specifier	*ft_init_format_specifier(void);

#endif