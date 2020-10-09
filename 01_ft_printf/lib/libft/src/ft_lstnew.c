/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 23:27:57 by jaeskim           #+#    #+#             */
/*   Updated: 2020/09/28 00:30:49 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_lstnew -  returns a new element with initialized
*/

t_list	*ft_lstnew(void *content)
{
	t_list	*result;

	if (!(result = malloc(sizeof(t_list))))
		return (0);
	result->content = content;
	result->next = 0;
	return (result);
}
