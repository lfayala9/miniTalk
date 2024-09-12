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
SRCS_BONUS = server.c client.c utils.c
OBJS = ${SRCS:.c=.o}
OBJS_BONUS = ${SRCS_BONUS:.c=.o}
#INCLUDE = -I include

all:	server client

bonus:	server_bonus client_bonus

server: $(OBJS)
			@make -C printf
			@cc $(FLAGS) server.c -I include printf/libftprintf.a -o server
client: $(OBJS)
			@make -C printf
			@cc $(FLAGS) client.c utils.c -I include printf/libftprintf.a -o client
server_bonus: $(OBJS_BONUS)
			@make -C printf
			@cc $(FLAGS) server_bonus.c -I include printf/libftprintf.a -o server_bonus
client_bonus: $(OBJS_BONUS)
			@make -C printf
			@cc $(FLAGS) client_bonus.c utils.c -I include printf/libftprintf.a -o client_bonus
clean:	
		@make clean -C printf
		@rm -rf $(OBJS)

fclean:	
		@make fclean -C printf
		@rm -rf $(OBJS) $(OBJS_BONUS)
		@rm -rf server client server_bonus client_bonus
re: all flcean

.PHONY: all re clean fclean bonus