# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/20 18:52:29 by mflavio-          #+#    #+#              #
#    Updated: 2023/08/30 23:26:48 by dmanoel-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

FLAGS = -Wall -Wextra -Werror -g

SRC_DIR = src
OBJ_DIR = obj

SRC_FILES =		\
				utils/message.c     \
				echo.c				\
				env_manager.c		\
				env_manager2.c		\
				execute.c			\
				exit.c				\
				free_tables.c		\
				get_line.c			\
				hash.c				\
				insert_env.c		\
				lexemizer_utils.c	\
				lexemizer.c			\
				lexer.c 			\
				main_loop.c			\
				minishell_manager.c \
				main.c  			\
				pwd.c

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

LIBFT = libft/libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C libft/

$(NAME): $(OBJ) $(LIBFT)
	gcc $(FLAGS) -o $@ $^ -lreadline

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)/utils
	gcc $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C libft/ clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C libft/ fclean

re: fclean all

valgrind : all
	valgrind --leak-check=full --show-leak-kinds=all --suppressions=suppressions ./minishell