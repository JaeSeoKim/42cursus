/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint_type.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 12:33:04 by jaeskim           #+#    #+#             */
/*   Updated: 2020/11/06 19:51:14 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BIGINT_TYPE_H
# define FT_BIGINT_TYPE_H

typedef struct	s_bigint
{
	char		*num;
	int			sign;
	int			len;
}				t_bigint;

#endif
