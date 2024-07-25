# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: layala-s <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/25 17:08:07 by layala-s          #+#    #+#              #
#    Updated: 2024/07/25 17:08:10 by layala-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror
SRCS = server.c
OBJS = ${SRCS:.c=.o}
#INCLUDE = -I include

all:	server

server: $(OBJS)
			@make -C printf
			@gcc $(FLAGS) server.c -I include printf/libftprintf.a -o server

clean:	
		@make clean -C printf
		@rm -rf $(OBJS)

fclean:	
		@make fclean -C printf
		@rm -rf $(OBJS)
		@rm -rf server
re: all flcean

.PHONY: all re clean fclean