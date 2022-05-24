
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggane <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/07 10:38:58 by ggane             #+#    #+#              #
#    Updated: 2016/12/19 01:04:52 by ggane            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a
CC=gcc
CFLAGS=-Wall -Wextra -Werror
RM=rm -f
LDFLAGS=-L.
LDLIBS=-lft
SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

%.o: %.c
		$(CC) -I. -o $@ -c $? $(CFLAGS)

all: $(NAME)

bonus: $(OBJB)
		ar rc $(NAME) $(OBJB)
		ranlib $(NAME)

clean:
		$(RM) $(OBJ)
		$(RM) $(OBJB)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: clean clean