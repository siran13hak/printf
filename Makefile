# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sihakoby <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/24 09:29:44 by sihakoby          #+#    #+#              #
#    Updated: 2025/02/24 12:28:20 by sihakoby         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
CC = cc

NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror 

INCS = printf.h

SRCS = ft_printf.c helper_functions.c

OBJS = $(SRCS:.c=.o)

all:  $(NAME)

$(NAME): $(OBJS)
	ar -rcs $@ $^

%.o: %.c $(INCS) Makefile
	$(CC) $(CFLAGS) -I $(INCL) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
