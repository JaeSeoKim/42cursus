/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 00:05:59 by jaeskim           #+#    #+#             */
/*   Updated: 2020/10/26 00:37:29 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_lstadd_back - Adds the element 'new' at the end of the list.
*/

void	ft_lstadd_back(t_list **lst, t_list *new_list)
{
	if (*lst == 0)
		*lst = new_list;
	else
		(ft_lstlast(*lst))->next = new_list;
}
