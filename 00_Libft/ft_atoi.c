/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 12:33:46 by jaeskim           #+#    #+#             */
/*   Updated: 2020/09/28 02:45:03 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_isspace - checks for white-space characters.
** (' ', '\f', '\n', '\r', '\t', '\v')
*/

static int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

/*
** ft_atoi - convert a string to an integer
*/

int			ft_atoi(const char *nptr)
{
	int result;
	int flag;

	result = 0;
	flag = 1;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
		if (*nptr++ == '-')
			flag *= -1;
	while (ft_isdigit(*nptr))
	{
		result *= 10;
		result += *nptr++ - '0';
	}
	return (result * flag);
}
