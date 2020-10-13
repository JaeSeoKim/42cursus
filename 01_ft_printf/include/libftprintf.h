/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 01:49:19 by jaeskim           #+#    #+#             */
/*   Updated: 2020/10/13 20:27:41 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <libft.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_sprintf(char *out, const char *format, ...);

int		ft_print_int(char **out, char **format, va_list ap);
int		ft_print_char(char **out, char **format, va_list ap);

void	ft_putchar_out(char **out, char c);
void	ft_putstr_out(char **out, char *s);

#endif
