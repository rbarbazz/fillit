/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_tetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 16:36:21 by aurlic            #+#    #+#             */
/*   Updated: 2017/11/30 17:09:39 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

int			test_bin(char *str)
{
	int				i;
	unsigned short	bin;

	bin = 0;
	i = 0;
	while (str[i])
	{
		bin = bin << 1;
		if (str[i] == '#')
			bin++;
		i++;
	}
	if ((check_t(bin) != 1) && (check_l(bin) != 1) && (check_z(bin) != 1) &&
			(check_odd(bin) != 1))
		return (1);
	return (0);
}

int			check_t(unsigned short bin)
{
	if (bin == 35968)
		return (1);
	else if (bin == 58368)
		return (1);
	else if (bin == 19968)
		return (1);
	else if (bin == 19520)
		return (1);
	else
		return (0);
}

int			check_l(unsigned short bin)
{
	if (bin == 57856)
		return (1);
	else if (bin == 36352)
		return (1);
	else if (bin == 35008)
		return (1);
	else if (bin == 17600)
		return (1);
	else if (bin == 59392)
		return (1);
	else if (bin == 11776)
		return (1);
	else if (bin == 50240)
		return (1);
	else if (bin == 51328)
		return (1);
	else
		return (0);
}

int			check_z(unsigned short bin)
{
	if (bin == 35904)
		return (1);
	else if (bin == 19584)
		return (1);
	else if (bin == 50688)
		return (1);
	else if (bin == 27648)
		return (1);
	else
		return (0);
}

int			check_odd(unsigned short bin)
{
	if (bin == 34952)
		return (1);
	else if (bin == 61440)
		return (1);
	else if (bin == 52224)
		return (1);
	else
		return (0);
}
