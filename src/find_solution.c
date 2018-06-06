/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_solution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 10:59:06 by rbarbazz          #+#    #+#             */
/*   Updated: 2017/12/05 14:32:42 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

int			cmp_map(t_tetri *piece, t_grid *end_map, size_t x, size_t y)
{
	int	i;
	int	j;
	int	letter;

	letter = 0;
	j = 0;
	while (j < piece->h)
	{
		i = 0;
		while (i < piece->w)
		{
			if (ft_isalpha(char_at(piece->content, i, j, 4)) != 0 &&
					char_at(end_map->data, x + i, y + j, end_map->size) == '.')
			{
				letter++;
			}
			i++;
		}
		j++;
	}
	if (letter != 4)
		return (1);
	place(piece, end_map, x, y);
	return (0);
}

int			place(t_tetri *piece, t_grid *end_map, size_t x, size_t y)
{
	int	i;
	int	j;
	int	letter;

	letter = 0;
	j = 0;
	while (j < piece->h)
	{
		i = 0;
		while (i < piece->w)
		{
			if (ft_isalpha(char_at(piece->content, i, j, 4)) != 0 &&
					char_at(end_map->data, x + i, y + j, end_map->size) == '.')
				end_map->data[(j + y) * end_map->size + (x + i)] =
					piece->content[j * 4 + i];
			i++;
		}
		j++;
	}
	if (letter != 4)
		return (1);
	return (0);
}

int			unplace(t_tetri *piece, t_grid *end_map)
{
	char	letter;
	int		i;

	i = 0;
	while (piece->content[i])
	{
		while (ft_isalpha(piece->content[i]) == 0)
			i++;
		if (ft_isalpha(piece->content[i]) == 1)
		{
			letter = piece->content[i];
			break ;
		}
	}
	i = 0;
	while (end_map->data[i])
	{
		if (end_map->data[i] == letter)
			end_map->data[i] = '.';
		i++;
	}
	return (0);
}

int			backtracking(t_tetri *piece, t_grid *end_map)
{
	size_t	x;
	size_t	y;

	if (!piece)
		return (1);
	y = 0;
	while (y < end_map->size - piece->h + 1)
	{
		x = 0;
		while (x < end_map->size - piece->w + 1)
		{
			if (cmp_map(piece, end_map, x, y) == 0)
			{
				if (backtracking(piece->next, end_map))
					return (1);
				else
					unplace(piece, end_map);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int			algoswag(t_tetri *piece)
{
	t_grid		*end_map;
	int			add;

	add = 0;
	if (count_tetri(piece) > 26)
		return (1);
	if ((piece->w == 4 && piece->h == 1) && (count_tetri(piece) == 1))
		add = 2;
	if ((piece->w == 1 && piece->h == 4) && (count_tetri(piece) == 1))
		add = 2;
	end_map = new_grid(piece, add);
	while (backtracking(piece, end_map) != 1)
	{
		add++;
		end_map = new_grid(piece, add);
	}
	print_map(end_map);
	return (0);
}
