/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_grid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 10:59:30 by rbarbazz          #+#    #+#             */
/*   Updated: 2017/12/05 13:52:58 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

int		count_tetri(t_tetri *start)
{
	int		i;
	t_tetri	*tmp;

	i = 1;
	tmp = start;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

t_grid	*new_grid(t_tetri *start, int add)
{
	t_grid	*greed;
	int		side;

	greed = (t_grid*)malloc(sizeof(t_grid));
	side = ft_sqrt(4 * (count_tetri(start) + add));
	greed->data = (char*)malloc(sizeof(char) * ((side * side) + 1));
	ft_memset(greed->data, '.', (side * side));
	greed->size = side;
	return (greed);
}
