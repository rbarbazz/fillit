/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 16:53:08 by rbarbazz          #+#    #+#             */
/*   Updated: 2017/12/04 13:08:55 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

char				*replace_n(char *buffer)
{
	size_t		index;
	size_t		rindex;
	size_t		len;
	char		*replaced;

	len = ft_strlen(buffer);
	replaced = (char*)malloc(sizeof(char) * len);
	index = 0;
	rindex = 0;
	while (index < len)
	{
		while (buffer[index] == '\n')
			index++;
		replaced[rindex] = buffer[index];
		rindex++;
		index++;
	}
	replaced[rindex] = '\0';
	return (replaced);
}

char				**split_maps(char *buffer)
{
	char			**maps;
	unsigned short	tabindex;
	unsigned short	sizetab;
	char			*replaced;

	replaced = replace_n(buffer);
	if (!(maps = (char**)malloc(sizeof(char*) * ((ft_strlen(replaced) - 1 / 16)
						+ 1))))
		return (NULL);
	tabindex = 0;
	while (*replaced)
	{
		sizetab = 0;
		maps[tabindex] = (char*)malloc(sizeof(char) * 17);
		while (sizetab < 16)
		{
			maps[tabindex][sizetab] = *replaced;
			replaced++;
			sizetab++;
		}
		maps[tabindex][sizetab] = '\0';
		tabindex++;
	}
	maps[tabindex] = NULL;
	return (maps);
}

unsigned short		check_lines(char *buffer)
{
	unsigned short	nbrchar;
	unsigned short	hashtag;

	nbrchar = 0;
	hashtag = 0;
	while ((*buffer == '.' || *buffer == '#') && nbrchar < 4)
	{
		if (*buffer == '#')
			hashtag++;
		nbrchar++;
		buffer++;
	}
	return (hashtag);
}

unsigned short		check_buffer(char *buffer)
{
	unsigned short	nbrline;
	unsigned short	validsize;

	while (buffer)
	{
		nbrline = 0;
		validsize = 0;
		while (nbrline < 4)
		{
			validsize = validsize + check_lines(buffer);
			buffer = buffer + 4;
			if (*buffer++ != '\n')
				return (1);
			nbrline++;
		}
		if (validsize != 4)
			return (1);
		if (*buffer == '\0')
			break ;
		if (*buffer++ != '\n')
			return (1);
	}
	return (0);
}

int					double_check_buffer(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] || buffer[i + 1])
	{
		if (buffer[i] != '.' && buffer[i] != '#' && buffer[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}
