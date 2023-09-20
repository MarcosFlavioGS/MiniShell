NAME = test.out

LIBFT_DIR = ../libft/
ASSERTZ_DIR = ./assertz/

LIBFT   = $(LIBFT_DIR)libft.a
ASSERTZ = $(ASSERTZ_DIR)assertz.a

SOURCES_PROGRAM  = \
					../src/executor/executor_utils.c\
					../src/executor/redirect/list_redirect.c\
					../src/executor/redirect/redirect.c\
					../src/executor/redirect/heredoc.c\
					../src/executor/string_array.c\
					../src/executor/simple_command.c\
					../src/env_manager.c\
					../src/env_manager2.c\
					../src/minishell_manager.c\
					../src/parser/grammar/grammar_rule.c\
					../src/parser/grammar/grammar_rule2.c\
					../src/parser/grammar/grammar.c\
					../src/parser/list_token.c\
					../src/parser/parser.c\
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
					../src/utils/message.c\
					../src/utils/syscall.c

SOURCES_TESTS    = \
					../debug/executor/simple_command_debug.c\
					../debug/executor/string_array_debug.c\
					../debug/executor/redirect/list_redirect_debug.c\
					../debug/debug_utils.c\
					../debug/token_list_utils.c\
					src/env_manager_test.c\
					src/env_manager2_test.c\
					src/executor/executor_utils_test.c\
					src/executor/redirect/heredoc_test.c\
					src/executor/simple_command_test.c\
					src/executor/string_array_test.c\
					src/parser/handler_dquotes_test.c\
					src/parser/handler_expand_test.c\
					src/parser/handler_expand2_test.c\
					src/parser/handler_quotes_test.c\
					src/parser/handler_separators_test.c\
					src/parser/handler_squotes_test.c\
					src/parser/handler_word_test.c\
					src/parser/list_token_test.c\
					src/parser/parser_test.c\
					src/parser/syntax_list_test.c\
					src/parser/lexer_test.c\
					src/parser/token_test.c\
					test_aux.c


SOURCES :=	$(SOURCES_PROGRAM)\
			$(SOURCES_TESTS)\
			main.c

CC = gcc

OBJECTS = $(SOURCES:.c=.o)
DEPENDS = $(SOURCES:.c=.d)

# recipes

all : $(NAME)

$(NAME) : $(LIBFT) $(ASSERTZ) $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LIBFT) $(ASSERTZ) -lreadline

%.o : %.c
	$(CC) -MMD -c $< -o $@ -DALL

-include $(DEPENDS)

fclean :
	rm -rf $(NAME)
	rm -rf $(OBJECTS)
	rm -rf $(DEPENDS)
	make -C $(ASSERTZ_DIR) clean
	make -C $(LIBFT_DIR) fclean

$(LIBFT) :
	make -C $(LIBFT_DIR)

$(ASSERTZ) :
	make -C $(ASSERTZ_DIR)

valgrind : all
	valgrind --suppressions=../suppressions \
	-q \
	--leak-check=full \
	--show-leak-kinds=all \
	--track-fds=yes \
	--track-origins=yes \
	--trace-children=yes \
	--trace-children-skip='*/bin/*,*/sbin/*' \
	./test.out

heredoc : all
	valgrind --suppressions=../suppressions \
	-q \
	--leak-check=full \
	--show-leak-kinds=all \
	--track-fds=yes \
	--track-origins=yes \
	--trace-children=yes \
	--trace-children-skip='*/bin/*,*/sbin/*' \
	./test.out heredoc_test

bash : all
	valgrind --suppressions=../suppressions \
	-q \
	--track-fds=yes \
	--track-origins=yes \
	--trace-children=yes \
	--trace-children-skip='*/bin/*,*/sbin/*' \
	bash