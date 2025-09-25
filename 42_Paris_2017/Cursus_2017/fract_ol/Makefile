# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maechard <maechard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 05:07:51 by maechard          #+#    #+#              #
#    Updated: 2017/11/21 00:51:06 by maechard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
PATH_INC = ./libft/includes/

CC = gcc
CFLAGS = -Wall -Wextra -Werror
DFLAGS = -lm -L libft/ -lft -lmlx -framework OpenGL -framework AppKit -I libft/libft.a

HEAD = include/ftl.h

ALLC = ftl_error.c ftl_cal.c ftl_color.c ftl_draw.c ftl_fractal.c \
		ftl_fractal_2.c  ftl_helper.c ftl_hook.c main.c

SRC = $(addprefix src/, $(ALLC))

OBJ = $(ALLC:.c=.o)
OBJ_DIR = $(addprefix obj/, $(OBJ))


all: $(NAME)

$(NAME): $(SRC)
	@make -C libft/
	@echo "<-------------------FRACTOL------------------->"
	@$(CC) $(CFLAGS) -I $(PATH_INC) -c $(SRC)
	@mkdir -p obj
	@mv $(OBJ) ./obj
	@$(CC) -o $(NAME) $(OBJ_DIR) $(DFLAGS)
	@echo "\033[32mBuilt fractol.\033[0m"

clean:
	@make -C libft/ clean
	@echo "<-------------------FRACTOL------------------->"
	@/bin/rm -rf ./obj
	@echo "\033[32mCleaned up object files.\033[0m"

fclean: clean
	@make -C libft/ fclean
	@echo "<-------------------FRACTOL------------------->"
	@/bin/rm -f $(NAME)
	@echo "\033[32mCleaned up compiled files.\033[0m"

re: fclean all

.PHONY: all lib clean fclean re