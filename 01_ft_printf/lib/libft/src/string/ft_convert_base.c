/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 19:56:00 by jaeskim           #+#    #+#             */
/*   Updated: 2020/10/26 16:33:48 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_convert_base(
	long long int num,
	const char *base_set,
	int base)
{
	char	*tmp;
	char	*result;

	if (num < 0)
	{
		tmp = ft_convert_base_unsigned(-num, base_set, base);
		result = ft_strjoin("-", tmp);
		free(tmp);
		return (result);
	}
	else
		return (ft_convert_base_unsigned(num, base_set, base));
}
