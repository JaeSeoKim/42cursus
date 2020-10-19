/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 18:05:46 by jaeskim           #+#    #+#             */
/*   Updated: 2020/10/19 22:43:48 by jaeskim          ###   ########.fr       */
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
void				ft_putchar_n_out(char **out, size_t n, char c);

t_format			*ft_init_format(char **out, char **foramt);

char				*ft_ullitoa(
					unsigned long long int n,
					t_format *pf);
void				ft_test_print_sturct(t_format *pf);

#endif