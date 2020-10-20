/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 16:59:48 by jaeskim           #+#    #+#             */
/*   Updated: 2020/10/20 23:24:19 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_H
# define FT_PRINT_H

# include <stdarg.h>
# include "ft_printf_sturct.h"

int						ft_print_number(va_list ap, t_format *pf);
int						ft_print_unsigned_number(va_list ap, t_format *pf);

long long int			ft_get_extend_id(va_list ap, t_format *pf);
unsigned long long int	ft_get_extend_u(va_list ap, t_format *pf);

#endif
