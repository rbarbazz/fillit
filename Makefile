# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aurlic <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/15 18:41:12 by aurlic            #+#    #+#              #
#    Updated: 2017/12/04 13:10:37 by aurlic           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

LIB = ./src/libft/libft.a

SRC = ./src/main.c \
	  ./src/find_map.c \
	  ./src/move_top_left.c \
	  ./src/to_letters.c \
	  ./src/valid_tetri.c \
	  ./src/new_grid.c \
	  ./src/find_solution.c \
	  ./src/find_pos.c \
	  ./src/valid_pts.c \

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c
	gcc $(FLAGS) -o $@ -c $<

$(LIB): 
	make -C ./src/libft

$(NAME): $(LIB) $(OBJ)
	gcc -o $(NAME) $(FLAGS) $(OBJ) $(LIB)

clean:
	rm -f $(OBJ)
	make -C ./src/libft clean

fclean: clean
	rm -f $(NAME)
	make -C ./src/libft fclean

re: fclean all
