# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysibous <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/18 16:10:47 by ysibous           #+#    #+#              #
#    Updated: 2018/03/20 16:10:12 by ysibous          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf.a

FILES = main.c
FILES += load_file.c

CC = gcc
FLAGS = -Wall -Wextra -Werror

SRC = $(addprefix src/, $(FILES))
OBJ = $(addprefix build/, $(FILES:.c=.o))

FRAMEW = -framework OpenGL -framework Appkit

I_MINILIBX = -I includes/minilibx
L_MINILIBX = -L includes/minilibx -lmlx
MINILIBX = $(I_MINILIBX) $(L_MINILIBX)

I_LIBFT = -I includes/libft
L_LIBFT = -L includes/libft -lft
LIBFT = $(I_LIBFT) $(L_LIBFT)

I_LIBGFX = -I includes/libgfx
L_LIBGFX = -L includes/libgfx -lgfx
LIBGFX = $(I_LIBGFX) $(L_LIBGFX)

all: $(NAME)

re: fclean all

regfx:
	make -C libgfx re
	make re

libft/libft.a: 
	make -C includes/libft re

libgfx/libgfx.a: 
	make -C includes/libgfx re

minilibx/libmlx.a: 
	make -C includes/minilibx re

$(NAME): libft/libft.a libgfx/libgfx.a  minilibx/libmlx.a $(OBJ)
		$(CC) $(FLAGS) $(MINILIBX) $(LIBFT) $(LIBFDF) $(LIBGFX) -I . $(FRAMEW) \
			$(OBJ) -o $(NAME)

build:
		mkdir build

build/%.o: src/%.c | build
		$(CC) $(FLAGS) $(I_MINILIBX) $(LIBFT) $(LIBGFX) -I . -c $< -o $@

clean:
		rm -rf build

tclean:
		make -C includes/libft fclean
		make -C includes/libgfx fclean
		make -C minilibx clean
		make fclean

fclean: clean
		rm -f $(NAME)
