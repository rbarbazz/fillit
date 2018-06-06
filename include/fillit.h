/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 17:56:33 by rbarbazz          #+#    #+#             */
/*   Updated: 2017/12/05 13:31:54 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/types.h>
# include "../src/libft/libft.h"
# define BUFF_SIZE 4096

typedef struct		s_grid
{
	char	*data;
	size_t	size;
}					t_grid;

typedef struct		s_tetri
{
	char			*content;
	size_t			content_size;
	int				w;
	int				h;
	struct s_tetri	*next;
	int				count;
}					t_tetri;

char				*replace_n(char *buffer);
char				**split_maps(char *replaced);
unsigned short		check_lines(char *buffer);
unsigned short		check_buffer(char *buffer);
char				**split_in_four(char *map);
char				**remove_extra_lines(char **divfour);
char				**remove_extra_columns(char **divfour);
char				*move_top_left(char *map);
int					test_bin(char *str);
int					check_t(unsigned short bin);
int					check_l(unsigned short bin);
int					check_z(unsigned short bin);
int					check_odd(unsigned short bin);
char				*to_letters(char *str, int alpha);
t_tetri				*ft_fil_lstnew(void const *content, size_t content_size);
void				ft_lstpush(t_tetri *alst, t_tetri *new);
t_tetri				*str_to_lst(char **tetri);
int					count_tetri(t_tetri *start);
t_grid				*new_grid(t_tetri *start, int add);
int					cmp_map(t_tetri *piece, t_grid *end_map,
		size_t x, size_t y);
int					place(t_tetri *piece, t_grid *endmap, size_t x, size_t y);
int					unplace(t_tetri *piece, t_grid *end_map);
int					backtracking(t_tetri *piece, t_grid *end_map);
int					algoswag(t_tetri *piece);
char				char_at(char *buffer, int x, int y, size_t size);
int					print_map(t_grid *greed);
int					find_width(t_tetri *piece);
t_tetri				*check_and_set(char *buffer);
int					resolve(char *buffer);
int					find_height(t_tetri *piece);
int					double_check_buffer(char *buffer);
int					valid_dots(char *buffer);

#endif
