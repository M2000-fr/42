# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mechard <mechard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/15 16:12:16 by mechard           #+#    #+#              #
#    Updated: 2023/08/18 12:09:58 by mechard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

FLAGS		= -Wall -Wextra -Werror

SRCS		= ./srcs/ft_putchar.c ./srcs/ft_putstr.c ./srcs/ft_strcmp.c ./srcs/ft_strlen.c ./srcs/ft_swap.c
OBJS		= ./srcs/ft_putchar.o ./srcs/ft_putstr.o ./srcs/ft_strcmp.o ./srcs/ft_strlen.o ./srcs/ft_swap.o

HEAD		= -I ./includes

all: $(NAME)

$(NAME):
	gcc -c $(FLAGS) $(SRCS) $(HEAD)
	mv ft_putchar.o ./srcs
	mv ft_swap.o ./srcs
	mv ft_putstr.o ./srcs
	mv ft_strlen.o ./srcs
	mv ft_strcmp.o ./srcs
	ar rc libft.a $(OBJS)
	ranlib libft.a

clean:
	-rm $(OBJS)

fclean: clean
	-rm $(NAME)

re: fclean all