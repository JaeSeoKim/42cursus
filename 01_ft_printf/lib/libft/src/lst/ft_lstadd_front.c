/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 23:36:53 by jaeskim           #+#    #+#             */
/*   Updated: 2020/10/26 00:37:28 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_lstadd_front - Adds the element 'new' at the beginning of the list.
*/

void	ft_lstadd_front(t_list **lst, t_list *new_list)
{
	new_list->next = *lst;
	*lst = new_list;
}
