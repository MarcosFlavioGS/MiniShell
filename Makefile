# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mflavio- <mflavio-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/20 18:52:29 by mflavio-          #+#    #+#              #
#    Updated: 2023/06/27 19:33:33 by mflavio-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = mini_shell

FLAGS = -Wall -Wextra -Werror

SRC_DIR = src
OBJ_DIR = obj

SRC_FILES = 	main.c  			\
				init_tables.c		\
				lexer.c 			\
				lexer_utils.c		\
				lexemizer.c			\
				hash.c				\
				insert.c			\
				insert_builtins.c	\
				get_line.c			\
				execute.c			\
				insert_operators.c 	\
				insert_env.c		\
				echo.c				\
				pwd.c				\
				main_loop.c

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

LIBFT = libft/libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C libft/

$(NAME): $(OBJ) $(LIBFT)
	gcc $(FLAGS) -lreadline -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	gcc $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C libft/ clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C libft/ fclean

re: fclean all
