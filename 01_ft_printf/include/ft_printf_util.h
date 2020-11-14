/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 18:05:46 by jaeskim           #+#    #+#             */
/*   Updated: 2020/11/14 17:03:31 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_UTIL_H
# define FT_PRINTF_UTIL_H

# include <stdarg.h>
# include "libft.h"
# include "ft_printf_sturct.h"

t_format	*ft_init_format(char **out, char **foramt, int *cnt);

void		ft_putchar_out(char **out, int c);
void		ft_putwchar_out(char **out, int unicode);
void		ft_putchar_n_out(char **out, int n, int c);
void		ft_putstr_out(char **out, char *s);
int			ft_putstr_out_free(char **out, char *s);

char		*ft_convert_base_custom(
			unsigned long long int num,
			const char *base_set,
			int base,
			t_format *pf);
char		*ft_n_encoding_utf8(wchar_t *unicode, int n);
void		ft_test_print_sturct(t_format *pf);

#endif
