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

$(LIBFT):
	make -C ../libft/

$(ASSERTZ):
	make -C ./assertz/

valgrind : all
	valgrind --show-leak-kinds=all --leak-check=full ./$(NAME)