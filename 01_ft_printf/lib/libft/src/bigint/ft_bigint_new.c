/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 15:21:00 by jaeskim           #+#    #+#             */
/*   Updated: 2020/11/15 16:18:05 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_bigint_new2(t_bigint *result, char *tmp)
{
	int	i;

	i = 0;
	while (i < result->len)
	{
		result->num[i] = tmp[result->len - i - 1] - '0';
		++i;
	}
	free(tmp);
}

t_bigint	*ft_bigint_new(int64_t num)
{
	t_bigint	*result;
	char		*tmp;

	if (!(result = malloc(sizeof(t_bigint))))
		return (0);
	if (!(tmp = ft_convert_base(num, "0123456789", 10)))
	{
		free(result);
		return (0);
	}
	result->len = ft_strlen(tmp);
	if (!(result->num = malloc(sizeof(int) * result->len)))
	{
		ft_frees(2, result, tmp);
		return (0);
	}
	result->sign = num < 0 ? 1 : 0;
	ft_bigint_new2(result, tmp);
	return (result);
}
