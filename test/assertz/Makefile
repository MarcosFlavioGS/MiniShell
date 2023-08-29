NAME = assertz

SOURCES = assertz.c\
test_assertz.c

OBJECTS = $(SOURCES:.c=.o)
DEPENDE = $(SOURCES:.c=.d)

$(NAME) : $(OBJECTS)
	gcc $(OBJECTS) -o $@

%.o : %.c
	gcc -MMD -c $< -o $@

-include $(DEPENDE)

clean :
	rm -rf $(OBJECTS) $(DEPENDE) $(NAME)

.PHONY : clean
