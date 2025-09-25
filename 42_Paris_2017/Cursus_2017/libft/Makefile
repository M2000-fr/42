# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: laymard <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/11 19:48:57 by laymard           #+#    #+#              #
#    Updated: 2017/04/27 13:43:59 by maechard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = *.c 

OBJS = *.o

D_COLOR= \033[0m

#color_text#

BLACK1=  \033[30m
RED1=    \033[31m
GREEN1=  \033[32m
YELLOW1= \033[33m
BLUE1=   \033[34m
PINK1=   \033[35m
CYAN1=   \033[36m
GREY1=   \033[37m

#color_background#

BLACK2=  \033[40m
RED2=    \033[41m
GREEN2=  \033[42m
YELLOW2= \033[43m
BLUE2=   \033[44m
PINK2=   \033[45m
CYAN2=   \033[46m
GREY2=   \033[47m

all: $(NAME)

$(NAME):
	@gcc -Wall -Wextra -Werror -c $(SRCS)
	@echo "$(CYAN1)Compilation effectuer$(D_COLOR)"
	@ar rc $(NAME) $(OBJS)
	@echo "$(YELLOW1)libft.a a ete cree$(D_COLOR)"
	@ranlib $(NAME)
	@echo "$(PINK1)Et son annexe a ete cree$(D_COLOR)"

clean:
	@rm -f *.o
	@echo "$(GREEN1)Les .o ont ete supprimer$(D_COLOR)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(GREEN1)La bibliotheque a egalement ete supprimer$(D_COLOR)"

re: fclean all
