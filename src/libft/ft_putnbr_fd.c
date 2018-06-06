/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 12:52:43 by aurlic            #+#    #+#             */
/*   Updated: 2017/11/08 12:56:11 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long nb2;

	nb2 = n;
	if (nb2 < 0)
	{
		ft_putchar_fd('-', fd);
		nb2 = nb2 * (-1);
	}
	if (nb2 >= 0 && nb2 <= 9)
		ft_putchar_fd(nb2 + '0', fd);
	if (nb2 > 9)
	{
		ft_putnbr_fd(nb2 / 10, fd);
		ft_putnbr_fd(nb2 % 10, fd);
	}
}
