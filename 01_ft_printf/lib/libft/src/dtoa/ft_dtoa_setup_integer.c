/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa_setup_integer.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 17:47:36 by jaeskim           #+#    #+#             */
/*   Updated: 2020/11/10 19:14:33 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_dtoa_util.h"

static void	ft_dtoa_setup_integer2(
	t_double n,
	char *integer,
	long significand,
	int exp)
{
	int		i;
	int		j;
	char	bit[FT_DBL_MAX_ARR];
	char	result[FT_DBL_MAX_ARR];
	char	tmp_mul[FT_DBL_INT_MAX_ARR];

	i = 0;
	j = FT_DBL_MAX_ARR - exp;
	ft_memset(bit, 0, sizeof(char) * FT_DBL_MAX_ARR);
	bit[j - 1] = 1;
	while (i < exp)
	{
		if (j == FT_DBL_MAX_ARR)
			break ;
		bit[j++] = (significand >> (exp - 1 - i++)) & 1 ? 1 : 0;
	}
	i = 0;
	while (i < FT_DBL_MAX_ARR)
		printf("%d", bit[i++]);
}

void	ft_dtoa_setup_integer(t_double n, char *integer)
{
	int		exp;
	long	significand;

	ft_memset(integer, 0, sizeof(char) * FT_DBL_INT_MAX_ARR);
	exp = n.exponent - (long)FT_DBL_BIAS;
	significand = n.significand >> (52 - exp);
	if (exp < 0)
		return ;
	ft_dtoa_setup_integer2(n, integer, significand, exp);
}
