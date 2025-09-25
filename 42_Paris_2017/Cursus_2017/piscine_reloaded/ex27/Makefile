# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maechard <maechard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/23 09:50:27 by maechard          #+#    #+#              #
#    Updated: 2017/04/10 21:02:49 by maechard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= ft_display_file
SRCS= ft_display_file.c
OBJS= ft_display_file.o
CC= gcc
FLAGS= -Wall -Wextra -Werror

all:
	@$(CC) -c $(FLAGS) $(SRCS)
	@gcc -o $(NAME) $(OBJS)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
