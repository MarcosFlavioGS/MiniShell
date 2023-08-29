NAME = assertz.a

SOURCES = \
			assertz.c\
			test_assertz.c

OBJECTS = $(SOURCES:.c=.o)
DEPENDE = $(SOURCES:.c=.d)

all : $(NAME)

$(NAME) : $(OBJECTS)
	ar -rcs $(NAME) $(OBJECTS)

%.o : %.c
	gcc -MMD -c $< -o $@

-include $(DEPENDE)

clean :
	rm -rf $(OBJECTS) $(DEPENDE) $(NAME)

.PHONY : clean
