/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_n_encoding_utf8.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 22:21:12 by jaeskim           #+#    #+#             */
/*   Updated: 2020/10/28 05:40:53 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_n_encoding_utf8(wchar_t *unicode, int n)
{
	char	*result;
	char	*tmp;
	char	*tmp2;

	if (!unicode)
		return (ft_strdup("(null)"));
	result = ft_strdup("");
	if (n != -5)
		n -= ft_wchar_len(*unicode);
	while ((n == -5 || n >= 0) && *unicode)
	{
		tmp = ft_encoding_utf8_char(*unicode);
		tmp2 = ft_strjoin(result, tmp);
		ft_frees(2, tmp, result);
		result = tmp2;
		++unicode;
		if (n != -5)
			n -= ft_wchar_len(*unicode);
	}
	return (result);
}
