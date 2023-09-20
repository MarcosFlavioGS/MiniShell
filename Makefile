# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/20 18:52:29 by mflavio-          #+#    #+#              #
#    Updated: 2023/09/20 14:33:05 by dmanoel-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

FLAGS = -Wall -Wextra -Werror -g

SRC_DIR = src
OBJ_DIR = obj

SRC_FILES =		\
				executor/executor_utils.c		\
				executor/executor.c		\
				executor/heredoc_manager.c\
				executor/string_array.c			\
				executor/simple_command.c		\
				executor/redirect/heredoc.c\
				executor/redirect/list_redirect.c\
				executor/redirect/redirect.c\
				env_manager.c					\
				env_manager2.c					\
				minishell_manager.c				\
				parser/grammar/grammar_rule.c	\
				parser/grammar/grammar_rule2.c	\
				parser/grammar/grammar.c		\
				parser/list_token.c				\
				parser/syntax_list.c			\
				parser/token.c					\
				parser/token2.c					\
				parser/token3.c					\
				parser/token4.c					\
				parser/token5.c					\
				parser/peek.c					\
				parser/parser.c					\
				parser/lexer.c					\
				parser/handler_dquotes.c		\
				parser/handler_expand.c			\
				parser/handler_expand2.c		\
				parser/handler_separators.c		\
				parser/handler_quotes.c			\
				parser/handler_squotes.c		\
				parser/handler_word.c			\
				signal/signals.c\
				utils/message.c   				\
				utils/syscall.c   				\
				utils/syscall2.c   				\
				exit.c							\
				env_manager.c					\
				env_manager2.c					\
				get_line.c						\
				main_loop.c						\
				minishell_manager.c 			\
				main.c  						\
				pwd.c							\
				../debug/executor/redirect/list_redirect_debug.c\
				../debug/executor/simple_command_debug.c\
				../debug/executor/string_array_debug.c\
				../debug/debug_utils.c\
				../debug/token_list_utils.c

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
	mkdir -p $(OBJ_DIR)/executor
	mkdir -p $(OBJ_DIR)/executor/redirect
	mkdir -p $(OBJ_DIR)/parser
	mkdir -p $(OBJ_DIR)/parser/grammar
	mkdir -p $(OBJ_DIR)/signal
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
	valgrind --suppressions=suppressions \
	-q \
	--leak-check=full \
	--show-leak-kinds=all \
	--track-fds=yes \
	--track-origins=yes \
	--trace-children=yes \
	--trace-children-skip='*/bin/*,*/sbin/*' \
	./minishell