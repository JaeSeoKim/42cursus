/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_n_revers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 15:36:17 by jaeskim           #+#    #+#             */
/*   Updated: 2020/11/10 15:39:40 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_str_n_revers(char *a, size_t n)
{
	int		i;
	char	*tmp;

	if (!(tmp = malloc(sizeof(char) * n)))
		return (0);
	
}