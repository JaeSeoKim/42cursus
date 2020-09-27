/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 08:00:43 by jaeskim           #+#    #+#             */
/*   Updated: 2020/09/27 08:49:47 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_putnbr_fd - Outputs the integer ’n’ to the given file descriptor.
*/

void		ft_putnbr_fd(int n, int fd)
{
	unsigned int nbr;

	nbr = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nbr = -n;
	}
	if (nbr >= 10)
		ft_putnbr_fd(nbr / 10, fd);
	ft_putchar_fd(nbr % 10 + '0', fd);
}
