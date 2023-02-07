# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvogel <mvogel@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/25 09:25:35 by mvogel            #+#    #+#              #
#    Updated: 2023/02/07 13:53:23 by mvogel           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a

HEADER = ft_printf.h

CC = cc

CFLAGS = -Wall -Wextra -Werror

ARFLAGS = rc

SRC = ft_printf.c \
	convert_n_print.c

OBJ = $(SRC:.c=.o)

LIB_PATH = libft/

LIB_NAME = libft.a

LIB = $(addprefix $(LIB_PATH), $(LIB_NAME))

all: lib
	make $(NAME)

lib :
	make -C $(LIB_PATH)

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)

%.o: %.c Makefile $(HEADER)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	$(RM) $(OBJ)
	make clean -C $(LIB_PATH)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIB_PATH)

re: fclean
	$(MAKE) all

.PHONY: all clean fclean re lib
