/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 09:53:11 by rbarbazz          #+#    #+#             */
/*   Updated: 2017/12/05 14:07:26 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

t_tetri			*check_and_set(char *buffer)
{
	int		i;
	int		alpha;
	char	**tetri;

	i = 0;
	alpha = 0;
	if (valid_dots(buffer) == 1)
		return (0);
	if (check_buffer(buffer) == 1)
		return (0);
	if (double_check_buffer(buffer) == 1)
		return (0);
	tetri = split_maps(buffer);
	while (tetri[i])
	{
		tetri[i] = move_top_left(tetri[i]);
		if (test_bin(tetri[i]) == 1)
			return (0);
		i++;
	}
	i = 0;
	while (tetri[i])
		to_letters(tetri[i++], alpha++);
	return (str_to_lst(tetri));
}

int				print_map(t_grid *greed)
{
	int		i;
	size_t	n;

	i = 0;
	while (greed->data[i])
	{
		n = 0;
		while (n < greed->size)
		{
			ft_putchar(greed->data[i]);
			n++;
			i++;
		}
		ft_putchar('\n');
	}
	return (0);
}

int				resolve(char *buffer)
{
	t_tetri	*tetri;

	if ((tetri = check_and_set(buffer)) == 0)
		return (1);
	if (algoswag(tetri) == 1)
		return (1);
	return (0);
}

int				main(int argc, char **argv)
{
	char	buffer[BUFF_SIZE];
	int		fd;

	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)))
		{
			read(fd, buffer, BUFF_SIZE);
			if (resolve(buffer) == 1)
				ft_putstr("error\n");
		}
		close(fd);
	}
	else
		ft_putstr("usage: ./fillit file\n");
	return (0);
}
