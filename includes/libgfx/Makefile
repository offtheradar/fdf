# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysibous <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/16 14:50:23 by ysibous           #+#    #+#              #
#    Updated: 2018/03/19 13:08:09 by ysibous          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libgfx.a

FILES =		create_vertex_init_info.c
FILES +=	change_frame_of_reference.c
FILES +=	matrix_computations.c
FILES +=	matrix_rotations.c
FILES +=	matrix_transforms.c

CC = gcc
FLAGS = -Wall -Wextra -Werror

SRC = $(addprefix src/, $(FILES))
OBJ = $(addprefix build/, $(FILES:.c=.o))

LIBGFX = -I .
LIBFT = -I ../libft
LIBX = -I ../minilibx


all: $(NAME)

re: fclean all

clean:
		rm -rf build

fclean: clean
		rm -rf $(NAME)

build:
		mkdir build/

$(NAME): $(OBJ)
		@echo "Making $@"
		ar rcs $(NAME) $(OBJ)

build/%.o: src/%.c | build
		$(CC) $(FLAGS) $(LIBFT) $(LIBX) $(LIBGFX) -c $< -o $@

