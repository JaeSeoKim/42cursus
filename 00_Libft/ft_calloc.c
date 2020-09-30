/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 09:43:49 by jaeskim           #+#    #+#             */
/*   Updated: 2020/09/25 09:50:27 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** fr_calloc- allocate and free dynamic memory
*/

void	*ft_calloc(size_t nmemb, size_t size)
{
	void *result;

	if (!(result = malloc(nmemb * size)))
		return (0);
	ft_bzero(result, nmemb * size);
	return (result);
}
