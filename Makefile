# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysibous <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/23 18:15:35 by ysibous           #+#    #+#              #
#    Updated: 2018/03/25 11:41:30 by ysibous          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc
CFLAGS = -Wall -Wextra -Werror -o
FRAMEW = -framework OpenGL -framework Appkit

FILES = main.c
FILES += load_file.c

SRC = $(addprefix src/, $(FILES))

all: $(NAME)

MLIBX = includes/minilibx/libmlx.a

LIBFT = includes/libft/libft.a

LIBGFX = includes/libgfx/libgfx.a

mlibft.a: 
		make -C includes -C libft re

mlibgfx.a: 
		make -C includes -C libgfx re

mlibx.a: 
		make -C includes -C minilibx re

$(NAME): mlibft.a mlibgfx.a mlibx.a
	$(CC) $(CFLAGS) $(NAME) $(SRC) $(LIBFT) $(LIBGFX) $(LIBX) $(MLIBX) $(FRAMEW)
