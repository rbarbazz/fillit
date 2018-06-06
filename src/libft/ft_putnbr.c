/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:20:13 by aurlic            #+#    #+#             */
/*   Updated: 2017/11/08 12:56:13 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long nb2;

	nb2 = n;
	if (nb2 < 0)
	{
		ft_putchar('-');
		nb2 = nb2 * (-1);
	}
	if (nb2 >= 0 && nb2 <= 9)
		ft_putchar(nb2 + '0');
	if (nb2 > 9)
	{
		ft_putnbr(nb2 / 10);
		ft_putnbr(nb2 % 10);
	}
}
