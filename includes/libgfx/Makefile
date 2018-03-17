# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysibous <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/16 14:50:23 by ysibous           #+#    #+#              #
#    Updated: 2018/03/16 15:04:12 by ysibous          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libgfx.a

FILES =		create_vertex.c
FILES +=	matrix_computations.c
FILES +=	matrix_rotations.c
FILES +=	matrix_transformations.c

FLAGS = -Wall -Wextra -Werror

SRC = $(addprefix src/, $(FILES))
OBJ = $(addprefix build/. $(FILES:.c=.o))

LIBGFX = -I .
LIBFT = -I ../libft
LIBX = -I ../minilibx

.PHONY: all re clean fclean

all: $(NAME)

re: fclean all

clean:
		rm -rf build

fclean: clean
		rm -rf $(NAME)

build:
		mkdir build/
		src/*.c | build
		@echo "Building $@"
		gcc $(FLAGS) $(LIBFT) $(LIBX) $(LIBGFX) -c $< -o $@

$(NAME): $(OBJS)
		@echo "Making $@"
		ar rc $(NAME) $(OBJS)

