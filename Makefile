# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zaiicko <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/05 21:55:06 by zaiicko           #+#    #+#              #
#    Updated: 2024/09/05 23:40:45 by zaiicko          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zaiicko <meskrabe@student.s19.be>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/23 00:23:16 by zaiicko           #+#    #+#              #
#    Updated: 2024/09/03 18:05:36 by zaiicko          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
INC_DIR = inc
INC = -I$(INC_DIR) -I$(LIBFT_DIR)
SRC_DIR = srcs
OBJ_DIR = obj
RM = rm -rf

SRCS =	\

SRC = $(addprefix $(SRC_DIR)/, $(SRCS))

OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: logo $(NAME) 

$(NAME):	$(OBJ) $(LIBFT)
		@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
		@make -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
		@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(OBJ_DIR):
		@mkdir -p $(OBJ_DIR)

clean:
			@$(RM) $(OBJ_DIR)
			@make clean -C $(LIBFT_DIR)

fclean: clean
		@$(RM) $(NAME)
		@make fclean -C $(LIBFT_DIR)

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
