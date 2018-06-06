/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_top_left.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 10:38:53 by rbarbazz          #+#    #+#             */
/*   Updated: 2017/11/29 14:43:06 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

char	**split_in_four(char *map)
{
	char			**divfour;
	unsigned short	tabindex;
	unsigned short	sizetab;

	tabindex = 0;
	if (!(divfour = (char**)malloc(sizeof(char*) * 5)))
		return (NULL);
	while (*map)
	{
		sizetab = 0;
		divfour[tabindex] = (char*)malloc(sizeof(char) * 5);
		while (sizetab < 4)
		{
			divfour[tabindex][sizetab] = *map;
			map++;
			sizetab++;
		}
		divfour[tabindex][sizetab] = '\0';
		tabindex++;
	}
	divfour[tabindex] = NULL;
	return (divfour);
}

char	**remove_extra_lines(char **divfour)
{
	char	*swapline;

	while (!(ft_strcmp(divfour[0], "....\0")))
	{
		swapline = divfour[0];
		divfour[0] = divfour[1];
		divfour[1] = divfour[2];
		divfour[2] = divfour[3];
		divfour[3] = swapline;
	}
	return (divfour);
}

char	**remove_extra_columns(char **divfour)
{
	char			swapchar;
	unsigned short	index;

	while (divfour[0][0] != '#' && divfour[1][0] != '#' && divfour[2][0] != '#')
	{
		index = 0;
		while (index < 4)
		{
			swapchar = divfour[index][0];
			divfour[index][0] = divfour[index][1];
			divfour[index][1] = divfour[index][2];
			divfour[index][2] = divfour[index][3];
			divfour[index][3] = swapchar;
			index++;
		}
	}
	return (divfour);
}

char	*move_top_left(char *map)
{
	char			*cleanmap;
	unsigned short	index;
	char			**divfour;

	divfour = split_in_four(map);
	if (!(cleanmap = (char*)ft_memalloc(sizeof(char) * 17)))
		return (NULL);
	divfour = remove_extra_lines(divfour);
	divfour = remove_extra_columns(divfour);
	index = 0;
	while (index < 4)
	{
		cleanmap = ft_strcat(cleanmap, divfour[index]);
		index++;
	}
	return (cleanmap);
}
