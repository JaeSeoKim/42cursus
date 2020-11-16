/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 18:05:46 by jaeskim           #+#    #+#             */
/*   Updated: 2020/11/17 05:49:26 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_UTIL_H
# define FT_PRINTF_UTIL_H

# include <stdarg.h>
# include "libft.h"
# include "ft_printf_type.h"

t_format	*ft_init_format(char **out, char **foramt, int *cnt);

void		ft_putchar_out(char **out, int c);
void		ft_putwchar_out(char **out, int unicode);
void		ft_putchar_n_out(char **out, int n, int c);
void		ft_putstr_out(char **out, char *s);
int			ft_putstr_out_free(char **out, char *s);

char		*ft_convert_base_custom(
			t_ull num,
			const char *base_set,
			int base,
			t_format *pf);
char		*ft_n_encoding_utf8(wchar_t *unicode, int n);

char		*ft_custom_dtoa(double n, t_format *pf, char spec);

#endif
