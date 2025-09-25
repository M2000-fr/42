# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mechard <mechard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/22 04:31:00 by mechard           #+#    #+#              #
#    Updated: 2023/08/23 21:49:53 by mechard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= bsq

FLAGS	= -c -Wall -Wextra -Werror

SRCS	= ./srcs/ft_check.c ./srcs/ft_parse.c ./srcs/ft_print.c ./srcs/ft_reader.c ./srcs/ft_reader_helper.c ./srcs/main.c ./srcs/ft_map_dd_init.c ./srcs/ft_convert.c ./srcs/ft_bsq.c
OBJ		= ft_check.o ft_parse.o ft_print.o ft_reader.o ft_reader_helper.o main.o ft_map_dd_init.o ft_convert.o ft_bsq.o
OBJS	= ./objs/*.o
INC		= ./includes/*.h
INCS	= -I ./includes

#reset_color#

D_COLOR = \033[0m

#color_text#

BLACK1	= \033[30m
RED1	= \033[31m
GREEN1	= \033[32m
YELLOW1	= \033[33m
BLUE1	= \033[34m
PINK1	= \033[35m
CYAN1	= \033[36m
GREY1	= \033[37m

#color_background#

BLACK2	= \033[40m
RED2	= \033[41m
GREEN2	= \033[42m
YELLOW2	= \033[43m
BLUE2	= \033[44m
PINK2	= \033[45m
CYAN2	= \033[46m
GREY2	= \033[47m

all: $(NAME)

$(NAME): compilation $(OBJS)
	@cc $(OBJS) -o $(NAME)
	@echo "                compilation du rush-02 \033[32mOK$(D_COLOR)"

$(OBJS): $(SRCS)
	@cc $(FLAGS) $(INCS) $(SRCS)
	@echo "                  compilation des .c \033[32mOK$(D_COLOR)"
	-@mkdir objs
	@mv $(OBJ) ./objs

compilation:
	@echo "\n----------------------$(BLUE1)Compilation$(D_COLOR)----------------------\n"
	
norme:
	@echo "\n----------------------$(PINK2)$(BLACK1)Norminette$(D_COLOR)------------------------\n"
	@norminette $(SRCS)
	@norminette $(INC)
	@echo "\n                    NORMINETTE $(PINK1)OK$(D_COLOR)"

clean:
	@rm -rf ./objs
	@echo "\n----------------------$(YELLOW1)Folder Clean$(D_COLOR)----------------------\n"
	@echo "                Fichiers objets $(RED1)SUPPRIME$(D_COLOR)"

cmpclean: all clean

leaks:
	@valgrind memusage ./$(NAME)

fclean: clean
	@rm -f $(NAME)
	@echo "                     rush-02 $(RED)SUPPRIME$(D_COLOR)"

re: cmpclean

.PHONY: clean fclean re all