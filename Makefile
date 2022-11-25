# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvogel <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/25 09:25:35 by mvogel            #+#    #+#              #
#    Updated: 2022/11/25 09:25:37 by mvogel           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a

HEADER = libftprintf.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror

ARFLAGS = rc

SRC = ft_printf.c \


OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)

%.o: %.c Makefile $(HEADER)
	$(CC) $(CFLAGS) -I $(HEADER) -o $@ -c $<

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE) all

.PHONY: all bonus clean fclean re