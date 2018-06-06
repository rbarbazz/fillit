/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 15:59:33 by aurlic            #+#    #+#             */
/*   Updated: 2017/11/30 16:06:04 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

int				find_width(t_tetri *piece)
{
	int	x;
	int	y;
	int	temp;
	int	width;

	temp = 0;
	x = 0;
	width = 0;
	while (x < 4)
	{
		y = 0;
		temp = 0;
		while (y < 4)
		{
			if (ft_isalpha(char_at(piece->content, x, y, 4)) != 0)
				temp++;
			y++;
		}
		if (temp != 0)
			width++;
		x++;
	}
	return (width);
}

int				find_height(t_tetri *piece)
{
	int	x;
	int	y;
	int	temp;
	int	height;

	temp = 0;
	y = 0;
	height = 0;
	while (y < 4)
	{
		x = 0;
		temp = 0;
		while (x < 4)
		{
			if (ft_isalpha(char_at(piece->content, x, y, 4)) != 0)
				temp++;
			x++;
		}
		if (temp != 0)
			height++;
		y++;
	}
	return (height);
}
