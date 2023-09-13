NAME = test.out

SOURCES_PROGRAM  = \
					../src/executor/executor_utils.c\
					../src/executor/string_array.c\
					../src/executor/simple_command.c\
					../src/env_manager.c\
					../src/env_manager2.c\
					../src/minishell_manager.c\
					../src/parser/list_token.c\
					../src/parser/syntax_list.c\
					../src/parser/token.c\
					../src/parser/token2.c\
					../src/parser/token3.c\
					../src/parser/token4.c\
					../src/parser/token5.c\
					../src/parser/peek.c\
					../src/parser/lexer.c\
					../src/parser/handler_dquotes.c\
					../src/parser/handler_expand.c\
					../src/parser/handler_expand2.c\
					../src/parser/handler_separators.c\
					../src/parser/handler_quotes.c\
					../src/parser/handler_squotes.c\
					../src/parser/handler_word.c\
					../src/utils/message.c

SOURCES_TESTS    = \
					../debug/executor/simple_command_debug.c\
					../debug/executor/string_array_debug.c\
					../debug/debug_utils.c\
					../debug/token_list_utils.c\
					test_aux.c\
					env_manager_test.c\
					env_manager2_test.c\
					executor/executor_utils_test.c\
					executor/simple_command_test.c\
					executor/string_array_test.c\
					parser/handler_dquotes_test.c\
					parser/handler_expand_test.c\
					parser/handler_expand2_test.c\
					parser/handler_quotes_test.c\
					parser/handler_separators_test.c\
					parser/handler_squotes_test.c\
					parser/handler_word_test.c\
					parser/list_token_test.c\
					parser/syntax_list_test.c\
					parser/lexer_test.c\
					parser/token_test.c

SOURCES :=	$(SOURCES_PROGRAM)\
			$(SOURCES_TESTS)\
			assertz/assertz.c\
			main.c

CC = gcc

OBJECTS = $(SOURCES:.c=.o)
DEPENDS = $(SOURCES:.c=.d)

LIBFT   = ../libft/libft.a
ASSERTZ = ./assertz/assertz.a

# recipes

all : $(NAME)

$(NAME) : $(LIBFT) $(ASSERTZ) $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LIBFT) $(ASSERTZ)

%.o : %.c
	$(CC) -MMD -c $< -o $@ -DALL

-include $(DEPENDS)

fclean :
	rm -rf $(NAME)
	rm -rf $(OBJECTS)
	rm -rf $(DEPENDS)
	make -C ./assertz/ clean
	make -C ../libft/ fclean

$(LIBFT):
	make -C ../libft/

$(ASSERTZ):
	make -C ./assertz/

valgrind : all
	valgrind --show-leak-kinds=all --leak-check=full ./$(NAME)