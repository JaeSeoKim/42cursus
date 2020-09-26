/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 16:37:32 by jaeskim           #+#    #+#             */
/*   Updated: 2020/09/26 16:39:16 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_isascii - checks whether c is a 7-bit unsigned char
** value that fits into the ASCII character set.
*/

int		ft_isascii(int c)
{
	return (c >= 0 && c < 128);
}
