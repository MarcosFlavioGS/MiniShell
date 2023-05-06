# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mflavio- <mflavio-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/20 18:52:29 by mflavio-          #+#    #+#              #
#    Updated: 2023/04/20 18:52:47 by mflavio-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = mini_shell

FLAGS = -Wall -Wextra -Werror -lreadline

SRC = 	src/main.c

OBJ = ${SRC:src/%.c=obj/%.o}

LIBFT = libft/libft.a

all: ${LIBFT} ${NAME}

${LIBFT}:
	$(MAKE) -C libft/

${NAME}: ${OBJ} ${LIBFT}
	gcc ${FLAGS} -o $@ $^

obj/%.o: src/%.c
	mkdir -p obj
	gcc ${FLAGS} -c $< -o $@

clean:
	rm -rf obj
	$(MAKE) -C libft/ clean

fclean: clean
	rm -rf ${NAME}
	$(MAKE) -C libft/ fclean

re: fclean all
