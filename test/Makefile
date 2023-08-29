NAME = test

SOURCES_PROGRAM  = \
					../src/env_manager.c\
					../src/env_manager2.c

SOURCES_TESTS    = \
					env_manager_test.c\
					env_manager2_test.c

SOURCES :=	$(SOURCES_PROGRAM)\
			$(SOURCES_TESTS)\
			assertz/assertz.c\
			main.c

CC = cc

NAME = test

OBJECTS = $(SOURCES:.c=.o)
DEPENDS = $(SOURCES:.c=.d)

LIBFT = ../libft/libft.a

# recipes

all : $(NAME)

$(NAME) : $(OBJECTS) $(LIBFT)
	$(CC) $(OBJECTS) -o $@ $(LIBFT)

%.o : %.c
	$(CC) -MMD -c $< -o $@ -DALL

-include $(DEPENDS)

test_stack_utils : all
	valgrind --leak-check=full --show-leak-kinds=all ./test 5

fclean :
	rm -rf $(NAME)
	rm -rf $(OBJECTS)
	rm -rf $(DEPENDS)

$(LIBFT):
	make -C ../libft/Makefile

valgrind : all
	valgrind --show-leak-kinds=all --leak-check=full ./$(NAME)
