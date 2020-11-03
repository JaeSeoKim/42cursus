/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa_util.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 00:42:20 by jaeskim           #+#    #+#             */
/*   Updated: 2020/11/03 14:33:45 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DTOA_UTIL_H
# define FT_DTOA_UTIL_H

# include "ft_dtoa_type.h"

char	*ft_dtoa_f(t_double n, int precision);

char	*ft_dtoa_ut_itoa(long integer, int sign);
int		ft_dtoa_ut_check_round(t_double n, int c, long integer, int precision);

#endif
