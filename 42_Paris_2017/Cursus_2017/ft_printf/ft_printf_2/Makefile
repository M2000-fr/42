# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maechard <maechard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/13 11:35:46 by maechard          #+#    #+#              #
#    Updated: 2018/07/26 03:32:24 by maechard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printf
PATH_SRC = ./
PATH_OBJ = ./
PATH_INC = ./libft/includes/

CC = gcc
CFLAGS = -Wall -Wextra -Werror 
DFLAGS = -lm -L libft/ -lft -lmlx -framework OpenGL -framework AppKit -I libft/libft.a

HEAD = include/fdf.h

ALLC = ft_printf.c ft_flagsScC.c ft_flagdDi.c ft_flageE.c ft_flagfF.c \
		ft_flagxX.c ft_flagoO.c main.c ft_error.c

SRC = $(addprefix src/, $(ALLC))

OBJ = $(ALLC:.c=.o)
OBJ_DIR = $(addprefix obj/, $(OBJ))


all: $(NAME)

$(NAME): $(SRC)
	@make -C libft/
	@echo "<------------------FT_PRINTF------------------>"
	@$(CC) $(CFLAGS) -I $(PATH_INC) -c $(SRC)
	@mkdir -p obj
	@mv $(OBJ) ./obj
	@$(CC) -o $(NAME) $(OBJ_DIR) $(DFLAGS)
	@echo "\033[32mBuilt printf.\033[0m"

.PHONY: clean fclean

clean:
	@make -C libft/ clean
	@echo "<------------------FT_PRINTF------------------>"
	@/bin/rm -f $(OBJ_DIR)
	@rm -rf obj
	@echo "\033[32mCleaned up object files.\033[0m"

fclean: clean
	@make -C libft/ fclean
	@echo "<------------------FT_PRINTF------------------>"
	@/bin/rm -f $(NAME)
	@echo "\033[32mCleaned up compiled files.\033[0m"

re: fclean all
