# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tarchen <tarchen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 05:07:51 by tarchen           #+#    #+#              #
#    Updated: 2017/11/21 00:51:06 by tarchen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printf
LIB = libftprintf.a

CC = gcc

CFLAGS = -c -Wall -Wextra -Werror
FLAGS = -g -o $(NAME)

MAIN = main.c 

SRC = ft_printf.c ft_flagsScC.c ft_flagdDi.c ft_flageE.c ft_flagfF.c \
		ft_flagoxOX.c ft_flagp.c

INC = libft/include/libft.h ft_printf.h

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(LIB): $(SRC) 
	@$(CC) $(CFLAGS) $(SRC) -I $(INC)
	@ar rc $(LIB) $(OBJ)
	@ranlib $(LIB)
	@echo "\033[36mrule \033[32m$(LIB):	Done.\033[0m"

$(NAME): $(LIB)
	@$(CC) $(FLAGS) $(MAIN) $(LIB) ./libft/libft.a
	@echo "\033[36mrule \033[32m$(NAME):		Done.\033[0m"

clean:
	@rm -f $(OBJ)
	@echo "\033[36mrule \033[32mclean:		Done.\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[36mrule \033[32mfclean:		Done.\033[0m"

re: fclean all clean

.PHONY: all lib clean fclean re