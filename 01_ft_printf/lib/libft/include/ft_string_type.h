/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_type.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 00:42:20 by jaeskim           #+#    #+#             */
/*   Updated: 2020/10/27 21:47:09 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_TYPE_H
# define FT_STRING_TYPE_H

union	u_dtoa
{
	long double	ld;
	char		c[16];
};

#endif
