/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 20:19:08 by jaeskim           #+#    #+#             */
/*   Updated: 2020/10/12 21:28:31 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_str_add_char_with_free(char *s1, char c)
{
	char	*result;
	size_t	s1_len;

	s1_len = ft_strlen(s1);
	if (!(result = malloc(sizeof(char) * (s1_len + 2))))
		return (0);
	ft_memcpy(result, s1, s1_len);
	result[s1_len] = c;
	result[s1_len + 1] = 0;
	if (s1)
		free(s1);
	return (result);
}
