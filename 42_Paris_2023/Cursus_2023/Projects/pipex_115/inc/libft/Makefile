# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mechard <mechard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/23 20:03:06 by abutet            #+#    #+#              #
#    Updated: 2024/03/04 16:12:25 by mechard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

#==================SOURCES==================

SRC		= ft_atoi.c ft_isalpha.c ft_lstadd_back.c ft_lstlast.c ft_memcmp.c \
			ft_nbrlen.c ft_putnbr_fd.c ft_strcmp.c ft_strlcat.c ft_strnstr.c \
			ft_toupper.c ft_bzero.c ft_isascii.c ft_lstadd_front.c ft_lstmap.c \
			ft_memcpy.c ft_printf.c ft_putstr_fd.c ft_strcpy.c ft_strlcpy.c \
			ft_strrchr.c get_next_line.c ft_calloc.c ft_isdigit.c ft_lstclear.c \
			ft_lstnew.c ft_memdel.c ft_print_mand.c ft_split.c ft_strdup.c \
			ft_strlen.c ft_strtrim.c get_next_line_utils.c ft_check.c \
			ft_isprint.c ft_lstdelone.c ft_lstsize.c ft_memmove.c \
			ft_putchar_fd.c ft_strcat.c ft_striteri.c ft_strmapi.c ft_substr.c \
			ft_isalnum.c ft_itoa.c ft_lstiter.c ft_memchr.c ft_memset.c \
			ft_putendl_fd.c ft_strchr.c ft_strjoin.c ft_strncmp.c ft_tolower.c
SRC_DIR	= src/

#===================OBJETS===================

OBJ		= $(SRC:.c=.o)
OBJ_DIR	= obj/

#===================HEADER===================

HEAD_DIR	= inc/

#===================VAR_GBL===================

SRCS	= $(addprefix $(SRC_DIR), $(SRC))
OBJS	= $(addprefix $(OBJ_DIR), $(OBJ))
HEADERS		= -I$(HEAD_DIR)

#====================COLOR====================

#_________RESET_COLOR__________

D_COLOR = \033[0m

#__________COLOR_TEXT__________

BLACK1	= \033[30m
RED1	= \033[31m
GREEN1	= \033[32m
YELLOW1	= \033[33m
BLUE1	= \033[34m
PINK1	= \033[35m
CYAN1	= \033[36m
GREY1	= \033[37m

#_______COLOR_BACKGROUND_______

BLACK2	= \033[40m
RED2	= \033[41m
GREEN2	= \033[42m
YELLOW2	= \033[43m
BLUE2	= \033[44m
PINK2	= \033[45m
CYAN2	= \033[46m
GREY2	= \033[47m

#====================RULES====================

$(OBJS): $(SRCS)
	@echo "==========$(YELLOW1)LIBFT$(D_COLOR)==========\n"
	@cc -Wall -Wextra -Werror $(HEADERS) -c $(SRCS)
	@mkdir -p obj/
	@mv $(OBJ) obj/

$(NAME) : $(OBJS)
	@ar rcs $(NAME) $(OBJS) > /dev/null 2>&1
	@ranlib $(NAME) > /dev/null 2>&1
	@echo "Libft : $(GREEN1)Ok$(D_COLOR)\n"

all : $(NAME)

clean :
	@echo "========$(CYAN1)OBJ_LIBFT$(D_COLOR)========\n"
	@rm -rf $(OBJ_DIR) > /dev/null 2>&1
	@echo "$(RED1)supprime !$(D_COLOR)\n"

fclean : clean
	@echo "=========$(CYAN1)LIBFT.A$(D_COLOR)=========\n"
	@rm -f $(NAME)  > /dev/null 2>&1
	@echo "$(RED1)supprime !$(D_COLOR)\n"

re : fclean all

.PHONY : all, clean, fclean, re, bonus
