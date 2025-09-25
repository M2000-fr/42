# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mechard <mechard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/23 20:03:06 by abutet            #+#    #+#              #
#    Updated: 2024/04/01 21:09:38 by mechard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
EXEC_DIR	= exec/

SUCCESS	= Ok
DELETED	= supprime !
SILENCE	= > /dev/null 2>&1

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
			ft_putendl_fd.c ft_strchr.c ft_strjoin.c ft_strncmp.c ft_tolower.c \
			ft_pipex.c pipex.c tools_pipex.c ft_atol.c ft_isnumeric.c \
			ft_next_separator.c ft_dstrclean.c
SRC_DIR	= src/

#===================OBJETS===================

OBJ		= $(SRC:.c=.o)
OBJ_DIR	= obj/

#===================HEADER====================

HEAD_DIR	= inc/

#===================VAR_GBL===================

SRCS	= $(addprefix $(SRC_DIR), $(SRC))
OBJS	= $(addprefix $(OBJ_DIR), $(OBJ))

#====================FLAG=====================

FLAG_CP	= -Wall -Wextra -Werror -g3
HEADERS	= -I$(HEAD_DIR)
CC		= cc $(FLAG_CP) $(HEADERS)
TO_OBJ	= -c

#====================COLOR=====================

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
	@echo "==========$(YELLOW1)LIBFT$(D_COLOR)=========="
	@make --no-print-directory -C ./ norminette
	@$(CC) $(TO_OBJ) $(SRCS)
	@mkdir -p $(OBJ_DIR)
	@mv $(OBJ) $(OBJ_DIR)
	@ar rcs $(NAME) $(OBJS) $(SILENCE)
	@ranlib $(NAME) $(SILENCE)
	@echo "$(NAME) : $(GREEN1)$(SUCCESS)$(D_COLOR)\n"
	@mkdir -p $(EXEC_DIR)
	@mv $(NAME) $(EXEC_DIR)

$(NAME) : $(OBJS)

all : $(NAME)

clean :
	@echo "========$(CYAN1)OBJ_LIBFT$(D_COLOR)========\n"
	@rm -rf $(OBJ_DIR) $(SILENCE)
	@echo "$(RED1)$(DELETED)$(D_COLOR)\n"

fclean : clean
	@echo "=========$(CYAN1)LIBFT.A$(D_COLOR)=========\n"
	@rm -rf $(EXEC_DIR) $(SILENCE)
	@echo "$(RED1)$(DELETED)$(D_COLOR)\n"

norminette : $(SRCS)
	-@norminette src/ > res_cmd || true
	-@grep 'Error' res_cmd > norminette || true
	-@norminette inc/ > res_cmd || true
	-@grep "Error" res_cmd >> norminette || true
	@rm res_cmd
	@if [ ! -s norminette ]; then \
    	rm norminette; \
		echo "\nnorminette des .c de $(NAME) : $(GREEN1)OK!$(D_COLOR)\n"; \
	else \
   		echo "\nnorminette des .c de $(NAME) : $(RED1)Erreur!$(D_COLOR)\n"; \
		cat norminette; \
		echo "\n"; \
		rm norminette; \
	fi

re : fclean all

.PHONY : all, clean, fclean, re, bonus
