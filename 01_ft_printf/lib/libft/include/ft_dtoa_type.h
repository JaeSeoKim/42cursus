/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa_type.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 00:42:20 by jaeskim           #+#    #+#             */
/*   Updated: 2020/11/10 17:49:37 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DTOA_TYPE_H
# define FT_DTOA_TYPE_H

#ifndef FT_DBL_BIAS
# define FT_DBL_BIAS 1023
#endif

#ifndef FT_DBL_EXP_NAN
# define FT_DBL_EXP_NAN 2047
#endif

#ifndef FT_DBL_MAX_ARR
# define FT_DBL_MAX_ARR 1074
#endif

#ifndef FT_DBL_INT_MAX_ARR
# define FT_DBL_INT_MAX_ARR 308
#endif

typedef struct	s_double
{
	union
	{
		struct
		{
			unsigned long	significand	:52;
			unsigned long	exponent	:11;
			unsigned long	sign		:1;
		};
		double	d;
	};
}				t_double;

#endif
