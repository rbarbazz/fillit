/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_letters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 13:21:00 by aurlic            #+#    #+#             */
/*   Updated: 2017/12/01 10:07:59 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

char			*to_letters(char *str, int alpha)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '#')
			str[i] = 'A' + alpha;
		i++;
	}
	return (str);
}

t_tetri			*ft_fil_lstnew(void const *content, size_t content_size)
{
	t_tetri		*new;

	if (!(new = (t_tetri*)malloc(sizeof(*new))))
		return (NULL);
	if (!content)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		if (!(new->content = malloc(content_size)))
		{
			free(new);
			return (NULL);
		}
		ft_memcpy(new->content, content, content_size);
		new->content_size = content_size;
		new->w = find_width(new);
		new->h = find_height(new);
	}
	new->next = NULL;
	return (new);
}

void			ft_lstpush(t_tetri *alst, t_tetri *new)
{
	while (alst->next != NULL)
		alst = alst->next;
	alst->next = new;
}

t_tetri			*str_to_lst(char **tetri)
{
	int		i;
	t_tetri	*start;

	i = 0;
	start = ft_fil_lstnew(tetri[i], 17);
	while (tetri[++i])
	{
		ft_lstpush(start, ft_fil_lstnew(tetri[i], 17));
	}
	return (start);
}

char			char_at(char *buffer, int x, int y, size_t size)
{
	return (buffer[(y * size + x)]);
}
