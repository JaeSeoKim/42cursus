/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint_to_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 15:06:16 by jaeskim           #+#    #+#             */
/*   Updated: 2020/11/06 19:36:49 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_bigint_to_str(t_bigint *bigint)
{
	int		i;
	char	*result;

	if (!(result = malloc(sizeof(char) * (bigint->len + 1))))
		return (0);
	i = 0;
	while (i < bigint->len)
	{
		result[i] = bigint->num[bigint->len - 1 - i] + '0';
		++i;
	}
	result[bigint->len] = 0;
	return (result);
}
