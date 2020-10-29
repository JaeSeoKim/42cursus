/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_type.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 00:42:20 by jaeskim           #+#    #+#             */
/*   Updated: 2020/10/29 20:03:30 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_TYPE_H
# define FT_STRING_TYPE_H

#ifndef FT_DOUBLE_BIAS
# define FT_DOUBLE_BIAS 1023
#endif

union u_double
{
	struct
	{
		unsigned long	frac	:52;
		unsigned long	exp		:11;
		unsigned long	sign	:1;
	};
	double	d;
};

#endif
