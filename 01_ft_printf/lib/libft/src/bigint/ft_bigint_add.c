/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 13:09:47 by jaeskim           #+#    #+#             */
/*   Updated: 2020/11/11 17:46:17 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_swap(t_bigint **a, t_bigint **b)
{
	t_bigint *tmp;

	if ((*a)->len < (*b)->len)
	{
		tmp = *a;
		*a = *b;
		*b = tmp;
	}
}

static void	ft_bintint_add2(t_bigint *a, t_bigint *b, t_bigint *result)
{
	int		round_flag;
	int		i;

	round_flag = 0;
	i = 0;
	while (i < a->len)
	{
		if (i < b->len)
			result->num[i] = a->num[i] + b->num[i] + round_flag;
		else
			result->num[i] = a->num[i] + round_flag;
		round_flag = result->num[i] / 10;
		result->num[i] = result->num[i] % 10;
		i++;
	}
	if (round_flag)
		result->num[i++] = round_flag;
	result->len = i;
}

t_bigint	*ft_bigint_add(t_bigint *a, t_bigint *b)
{
	t_bigint	*result;
	int			max_len;

	max_len = ft_max(a->len, b->len);
	ft_swap(&a, &b);
	if (!(result = malloc(sizeof(t_bigint))))
		return (0);
	if (!(result->num = malloc(sizeof(int) * (max_len + 1))))
	{
		free(result);
		return (0);
	}
	ft_bintint_add2(a, b, result);
	return (result);
}
