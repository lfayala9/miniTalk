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
SRCS = server.c client.c utils.c
OBJS = ${SRCS:.c=.o}
#INCLUDE = -I include

all:	server client

server: $(OBJS)
			@make -C printf
			@cc $(FLAGS) server.c -I include printf/libftprintf.a -o server
client: $(OBJS)
			@make -C printf
			@cc $(FLAGS) client.c utils.c -o client
clean:	
		@make clean -C printf
		@rm -rf $(OBJS)

fclean:	
		@make fclean -C printf
		@rm -rf $(OBJS)
		@rm -rf server client
re: all flcean

.PHONY: all re clean fclean