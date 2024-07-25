# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: layala-s <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/16 19:33:54 by layala-s          #+#    #+#              #
#    Updated: 2024/04/16 19:33:56 by layala-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c \
	   ft_putchar.c \
	   ft_putstr.c \
	   ft_putnbr.c \
	   ft_puthex.c \
	   ft_putpoint.c \
	   ft_putuns.c \

OBJS = ${SRCS:%.c=%.o}

CC = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): 
		gcc $(CC) -c $(SRCS) -I ./
		@ar rcs $(NAME) $(OBJS)

clean:
		@rm -f ${OBJS}

fclean: clean
		@rm -f ${NAME}

re : flcean all

.PHONY: all clean re flcean
