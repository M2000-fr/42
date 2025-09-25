# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maechard <maechard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/23 09:50:27 by maechard          #+#    #+#              #
#    Updated: 2017/04/16 05:46:11 by maechard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libft.a
SRCS= srcs/ft_putchar.c \
	 srcs/ft_putstr.c \
	 srcs/ft_strcmp.c \
	 srcs/ft_strlen.c \
	 srcs/ft_swap.c
CC= gcc
FLAGS= -Wall -Wextra -Werror
OBJ= ft_putchar.o \
	 ft_putstr.o \
	 ft_strcmp.o \
	 ft_strlen.o \
	 ft_swap.o

all:
	@$(CC) -c $(FLAGS) $(SRCS)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
