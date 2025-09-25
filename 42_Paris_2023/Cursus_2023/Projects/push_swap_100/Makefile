# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mechard <mechard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/15 12:44:13 by mechard           #+#    #+#              #
#    Updated: 2024/04/11 14:54:18 by mechard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#===================VAR_GBL===================

NAME			= push_swap
HEADER			= -Iinc -Iinc/libft/inc
TESTER			= complexity

CC 				= cc
CFLAGS			= -Wall -Wextra -Werror -g3

INC				= inc/

TOOLS			= ft_splitav.c error.c free.c push.c reverse_rotate.c rotate.c \
					swap.c search.c utils.c
TOOLS_PLACE		= $(addprefix tools/, $(TOOLS)) #chemin de tout les outils (les mooves, les free, les erreurs,... etc)

SORT			= set_a.c set_b.c sort.c sort3.c
SORT_PLACE		= $(addprefix sort/, $(SORT)) #chemin des fonstions de tri

FILES			= main.c $(TOOLS_PLACE) $(SORT_PLACE)
SRC				= $(addprefix src/, $(FILES)) #chemin complet pour tout les SRCS

SUCCESS	= Ok
DELETED	= supprime !
SILENCE	= > /dev/null 2>&1

#====================LIBFT====================

LIB				= libft
LIB_A			= $(addprefix $(LIB), .a) #inclu Libft, ft_printf, get_next_line et pipex
LIB_DIR			= $(addprefix $(INC), libft/)
LIB_PLACE		= $(addprefix $(LIB_DIR), exec/)
LIB_EXEC		= $(addprefix $(LIB_PLACE), $(LIB_A)) #chemin complet pour libft.a

#===================SRC_GBL===================

SRC_ALL			= $(SRC) $(LIB_EXEC) #variable pour tout les SRC et libft.a

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

$(NAME) : $(SRC_ALL)
	@echo "========$(YELLOW1)PUSH_SWAP$(D_COLOR)========"
	@make --no-print-directory -C ./ norminette
	@$(CC) $(CFLAGS) $(SRC_ALL) $(HEADER) -o $(NAME)
	@echo "./$(NAME) : $(GREEN1)Ok$(D_COLOR)\n"

$(LIB_EXEC) :
	@make --no-print-directory -C $(LIB_DIR) $(LIB_A) 

all : $(NAME)

bonus : all

clean : clean_lib

clean_lib :
	@make --no-print-directory -C $(LIB_DIR) clean

fclean : clean
	@make --no-print-directory -C $(LIB_DIR) fclean
	@echo "==========$(CYAN1)EXEC$(D_COLOR)===========\n"
	@rm -rf $(NAME)
	@echo "./push_swap : $(RED1)$(DELETED)$(D_COLOR)\n"

fclean_all : fclean
	@if [ -s push_swap_tester/complexity ]; then \
		echo "==========$(CYAN1)Complexity$(D_COLOR)===========\n"; \
		rm -rf push_swap_tester/; \
		echo "./$(TESTER) : $(RED1)$(DELETED)$(D_COLOR)\n"; \
	fi
	@if [ -s checker_linux ]; then \
		echo "==========$(CYAN1)Checker_linux$(D_COLOR)===========\n"; \
		rm -f ./checker_linux; \
		echo "./checker_linux : $(RED1)$(DELETED)$(D_COLOR)\n"; \
	fi	

norminette :
	-@norminette src/ > res_cmd || true
	-@grep 'Error' res_cmd > norminette || true
	-@norminette inc/push_swap.h > res_cmd || true
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