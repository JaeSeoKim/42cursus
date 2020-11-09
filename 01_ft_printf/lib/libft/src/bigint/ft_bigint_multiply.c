/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint_multiply.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 16:39:08 by jaeskim           #+#    #+#             */
/*   Updated: 2020/11/07 18:22:51 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_digist(int n)
{
	int count;

	count = 0;
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static void	t_bigint_multiply2(t_bigint *a, int num, t_bigint *result)
{
	int round;
	int i;

	round = 0;
	i = 0;
	while (i < a->len)
	{
		result->num[i] = (a->num[i] * num) + (round % 10);
		round = (round / 10) + (result->num[i] / 10);
		result->num[i] = (result->num[i] % 10);
		++i;
	}
	while (round)
	{

		result->num[i] = round % 10;
		round = (round / 10);
		++i;
	}
	result->len = i;
}

t_bigint	*ft_bigint_multiply(t_bigint *a, int num)
{
	t_bigint	*result;

	if (!(result = malloc(sizeof(t_bigint))))
		return (0);
	if (!(result->num = malloc(sizeof(int) * \
		(a->len + ft_count_digist(num)))))
	{
		free(result);
		return (0);
	}
	t_bigint_multiply2(a, num, result);
	if (num < 0)
		result->sign = a->sign ? 0 : 1;
	return (result);
}
