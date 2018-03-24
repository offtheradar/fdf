# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysibous <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/23 18:15:35 by ysibous           #+#    #+#              #
#    Updated: 2018/03/23 18:42:14 by ysibous          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
FRAMEW = -framework OpenGL -framework Appkit

FILES = main.c
FILES += load_file.c

SRC = $(addprefix src/, $(FILES))

all: $(NAME)

MLIBX: includes/minilibx/mlx.a

LIBFT: includes/libft/libft.a

LIBGFX: includes/libgfx/libgfx.a

mlibft.a: 
		make -C includes -C libft re

mlibgfx.a: 
		make -C includes -C libgfx re

mlibx.a: 
		make -C includes -C minilibx re

$(NAME): mlibft.a mlibgfx.a mlibx.a
	@$(CC) $(CFLAGS) $(SRC) $(LIBFT) $(LIBGFX) $(LIBX) $(MLIBX) $(FRAMEW)
