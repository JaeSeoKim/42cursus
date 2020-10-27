/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_type.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 00:45:32 by jaeskim           #+#    #+#             */
/*   Updated: 2020/10/27 21:41:47 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LST_TYPE_H
# define FT_LST_TYPE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

#endif
