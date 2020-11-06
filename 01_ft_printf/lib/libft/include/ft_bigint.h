/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 12:42:28 by jaeskim           #+#    #+#             */
/*   Updated: 2020/11/06 19:52:42 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BIGINT_H
# define FT_BIGINT_H

# include "libft.h"
# include "ft_bigint_type.h"

t_bigint	*ft_bigint_new(t_ll num);
void		ft_bigint_del(t_bigint *target);
char		*ft_bigint_to_str(t_bigint *bigint);
t_bigint	*ft_bigint_add(t_bigint *a, t_bigint *b);
t_bigint	*ft_bigint_multiply(t_bigint *a, int num);

#endif
