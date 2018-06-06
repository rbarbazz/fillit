/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 13:53:08 by aurlic            #+#    #+#             */
/*   Updated: 2017/11/11 13:56:07 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_recursive_power(int nb, int power)
{
	int result;

	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	{
		result = nb * ft_recursive_power(nb, (power - 1));
		return (result);
	}
}
