
LIBFT = ../libft/libft.a

utils_message: $(LIBFT)
	gcc utils/message_debug.c ../src/utils/message.c $(LIBFT) -o $@.out

$(LIBFT) :
	$(MAKE) -C ../libft/