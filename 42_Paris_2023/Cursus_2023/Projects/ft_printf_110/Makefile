# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mechard <mechard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/20 12:03:14 by mechard           #+#    #+#              #
#    Updated: 2023/12/26 15:25:25 by mechard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

EXEC		= printf

CC 			= cc
CFLAGS		= -Wall -Wextra -Werror -fPIC
LIB			= libft/libft.a
LIB_H		= libft/libft.h
PATH_LIB 	= libft/

SRCS		= ft_printf.c ft_print_mand.c ft_check.c

OBJS_B		= ft_putstr_fd.o ft_strdup.o ft_strlen.o ft_strcpy.o ft_isdigit.o \
				ft_nbrlen.o ft_atoi.o
OBJS_LIB 	= $(addprefix libft/, $(OBJS_B))

OBJS		= $(SRCS:.c=.o)

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

%.o: %.c
	@$(CC) $(CFLAGS) -I $(HEADER) -I $(LIB_H) -c $<

$(NAME) : $(OBJS)
	@echo "<---------------------$(BLUE1)FT_PRINTF$(D_COLOR)------------------>"
	@make --no-print-directory -C $(PATH_LIB) libft.a
	@echo "   <--------------------$(BLUE1)PRINTF$(D_COLOR)------------------>\n"
	@ar rcs $(NAME) $(OBJS) $(OBJS_LIB)
	@ranlib $(NAME)
	@echo "            compilation de libftprintf.a $(GREEN1)OK$(D_COLOR)\n"

all : $(NAME)

bonus : all

clean :
	@echo "\n<------------------$(YELLOW1)Folder Clean$(D_COLOR)----------------->\n"
	@make --no-print-directory -C $(PATH_LIB) clean
	@rm -f $(OBJS)

fclean : clean
	@make --no-print-directory -C $(PATH_LIB) fclean
	@rm -f $(NAME)
	@echo "              $(NAME) $(RED1)SUPPRIME$(D_COLOR)\n"

re : fclean all

.PHONY : all, clean, fclean, re