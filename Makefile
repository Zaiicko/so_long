# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zaiicko <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/05 21:55:06 by zaiicko           #+#    #+#              #
#    Updated: 2024/09/19 01:50:24 by zaiicko          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
MINILIBX_DIR = minilibx
MINILIBX = $(MINILIBX_DIR)/libmlx.a
INC_DIR = inc
INC = -I$(INC_DIR) -I$(LIBFT_DIR)
SRC_DIR = srcs
OBJ_DIR = obj
RM = rm -rf
INC_MLX = -I/opt/X11/include -I$(MINILIBX_DIR)
MLX_FLAGS = -Lminilibx -lmlx -L/usr/x11/lib -lXext -lX11 -framework OpenGL -framework AppKit

SRCS =	main.c\
	utils.c\
	loading_sprite.c\
	args_checker.c\
	loading_map.c\
	map_checker.c\
	map_checker2.c\

SRC = $(addprefix $(SRC_DIR)/, $(SRCS))

OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: logo $(NAME) 

$(NAME):	$(OBJ) $(LIBFT) $(MINILIBX)
		@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MINILIBX)  $(MLX_FLAGS) -o $(NAME)

$(MINILIBX):
		@make -C $(MINILIBX_DIR)

$(LIBFT):
		@make -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
		@$(CC) $(CFLAGS) -c $< -o $@ $(INC) $(INC_MLX)

$(OBJ_DIR):
		@mkdir -p $(OBJ_DIR)

clean:
			@$(RM) $(OBJ_DIR)
			@make clean -C $(LIBFT_DIR)

fclean: clean
		@$(RM) $(NAME)
		@make fclean -C $(LIBFT_DIR)
		@make clean -C $(MINILIBX_DIR)

re:		fclean all

logo:
	@echo "\033[31m"
	@echo "                                                             "
	@echo "                           _|                                "
	@echo "   _|_|_|    _|_|          _|    _|_|    _|_|_|      _|_|_|  "
	@echo " _|_|      _|    _|        _|  _|    _|  _|    _|  _|    _|  "
	@echo "     _|_|  _|    _|        _|  _|    _|  _|    _|  _|    _|  "
	@echo " _|_|_|      _|_|          _|    _|_|    _|    _|    _|_|_|  "
	@echo "                                                         _|  "
	@echo "                 _|_|_|_|_|                          _|_|    "
	@echo "                                                             "
	
.PHONY:	fclean re all clean logo
