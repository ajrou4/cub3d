# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: majrou <majrou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/30 20:01:57 by majrou            #+#    #+#              #
#    Updated: 2023/11/01 04:47:15 by majrou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = cub3D
SRC = main.c parse.c parse_color.c parse_texteur.c error.c raycasting/cub3d_utils1.c raycasting/cub3d_utils2.c raycasting/cub3d_utils3.c raycasting/cub3d_utils4.c raycasting/cub3d.c raycasting/cub3d_extra_fn.c  raycasting/cub3d_extra_fn1.c  raycasting/cub3d_extra_fn3.c raycasting/rays_logic.c raycasting/texteur.c utilse.c
CC = cc
CFLAG = -Wall -Wextra -Werror
OBJ = $(SRC:.c=.o)
libft = libft/libft.a
HEADER = cub3d.h
RM = rm -rf

all: $(NAME)

%.o: %.c
		@$(CC) $(CFLAG) -c $< -o $@ -I $(HEADER)

$(NAME): $(OBJ)
		@$(MAKE) -C libft all
		@$(CC) $(libft) $(OBJ) -o $(NAME) mlx/libmlx42.a -Iinclude -lglfw -L"/Users/majrou/goinfre/homebrew/opt/glfw/lib"
		@echo "Compiling up..."

clean :
		@rm -rf $(OBJ)
		@$(MAKE) clean -C libft
		@echo "Cleaning up..."

fclean : clean
		@rm -rf  $(NAME)
		@$(MAKE) fclean -C libft
		@echo "Full cleaning up..."

re : fclean all

.PHONY : all fclean clean re


run :
	@$(MAKE) $(re) && $(MAKE) clean &&./$(NAME) maps/map.cub
