# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/24 00:48:36 by jalves-c          #+#    #+#              #
#    Updated: 2023/04/24 01:13:13 by jalves-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = @gcc
FLAGS = -Wall -Wextra -Werror
SRC = src/server.c src/client.c
OBJ = $(patsubst src/%.c,obj/%.o,$(SRC))

all: obj server client 

bonus: obj server client

server: obj/server.o libft
	$(CC) -o $@ $< -Llibft -lft
	@ echo "\033[0;32mServer is compiled!\033[0m"

client: obj/client.o libft
	$(CC) -o $@ $< -Llibft -lft
	@ echo "\033[0;32mClient is compiled!\033[0m"

obj/%.o: src/%.c | obj
	$(CC) -c $(FLAGS) $< -o $@

obj:
	@mkdir -p obj

libft:
	@make -C libft 

clean:
	@rm -f $(OBJ)
	@make -C libft clean
	@ echo "\033[0;32mObject files successfully cleaned!\033[0m"
	
fclean: clean
	@rm -rf obj server client libft/libft.a
	@echo "\033[0;32mExecutables successfully cleaned!\033[0m"

re: fclean all

norm :
	@norminette
	@echo "\033[0;32mNorminette: OK!\033[0m"

.PHONY: all bonus libft clean fclean re obj