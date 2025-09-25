# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mechard <mechard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/15 12:44:13 by mechard           #+#    #+#              #
#    Updated: 2024/07/03 17:44:12 by mechard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#===================VAR_GBL===================

NAME			= so_long
HEADER			= -Iinc -Iinc/libft/inc -Iinc/minilibx-linux/
LIB_X11			= -lXext -lX11 -lm

MAIN_FILE		= so_long.c game.c

TOOLS_FILE		= verif_map.c key.c free.c init.c image.c coor.c moove.c \
					collectibles.c ff.c
TOOLS_PLACE		= $(addprefix tools/, $(TOOLS_FILE))


SRC_SL			= $(addprefix src/, $(MAIN_FILE)) $(addprefix src/, $(TOOLS_PLACE))

CC 				= cc
CFLAGS			= -Wall -Wextra -Werror -g3

INC				= inc/
#===================MESSAGE===================

SUCCESS	= Ok
DELETED	= supprime !
SILENCE	= > /dev/null 2>&1

#====================LIBFT====================

LIB				= libft.a
LIB_DIR			= $(addprefix $(INC), libft/)
LIB_EXEC		= $(addprefix $(LIB_DIR), exec/)
LIB_A			= $(addprefix $(LIB_EXEC), $(LIB))

#=====================MLX=====================

MLX				= libmlx.a
MIN				= minilibx-linux
LINK_MLX		= https://cdn.intra.42.fr/document/document/21439/minilibx-linux.tgz
MLX_DIR			= $(addprefix $(INC), $(MIN)/)
MLX_A			= $(addprefix $(MLX_DIR), $(MLX))

#===================SRC_GBL===================

SRCS			= $(SRC_SL) $(LIB_A)

#====================COLOR====================

#_________RESET_COLOR__________

D_COLOR = \033[0m

#__________TEXT_STYLE__________

BOLD = \033[1m

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

$(NAME) : $(SRCS) inc/so_long.h
	@echo "===========$(YELLOW1)MLX$(D_COLOR)==========\n"
	@if [ ! -d "$(MLX_DIR)" ]; then \
		echo "$(PINK1)Le dossier $(MIN) n'existe pas, téléchargement...$(D_COLOR)$(BOLD)$(GREY2)$(BLACK1)\n"; \
		mkdir -p $(MLX_DIR); \
		curl -o $(INC)/minilibx-linux.tgz $(LINK_MLX); \
		echo "$(D_COLOR)"; \
		tar -xzf $(INC)/minilibx-linux.tgz -C $(INC); \
		rm $(INC)/minilibx-linux.tgz; \
		echo "Le dossier a ete telecharge depuis ->\n$(GREEN1)$(BLACK2)$(LINK_MLX)$(D_COLOR)\n"; \
	fi
	@ make --no-print-directory -C $(MLX_DIR) all $(SILENCE)
	@echo "./minilibx : $(GREEN1)$(SUCCESS)$(D_COLOR)\n"
	@echo "=========$(YELLOW1)SO_LONG$(D_COLOR)========\n"
	@if [ -d "$(MLX_DIR)" ]; then \
		$(CC) $(CFLAGS) -IX11 $(SRCS) $(MLX_A) $(HEADER) $(LIB_X11) -o $(NAME); \
		echo "./so_long : $(GREEN1)$(SUCCESS)$(D_COLOR)\n"; \
	else \
		echo "$(YELLOW1)Sans le dossier $(MIN), la compilation est impossible !\n$(D_COLOR)"; \
	fi

$(LIB_A) :
	@ make --no-print-directory -C $(LIB_DIR) $(LIB) 

all : $(NAME)

bonus : all

clean : clean_lib

clean_lib :
ifeq ($(MAKECMDGOALS),fclean)
	@echo "==========$(CYAN1)MLX$(D_COLOR)==========\n"
	@if [ -d "$(MLX_DIR)" ]; then \
		make --no-print-directory -C $(MLX_DIR) clean $(SILENCE); \
		rm -rf $(MLX_DIR); \
		echo "$(RED1)$(DELETED)$(D_COLOR)\n"; \
	else \
		echo "$(PINK1)La suppression du superflu dans le dossier $(MIN) est impossible ! $(D_COLOR)\n"; \
	fi
endif
ifeq ($(MAKECMDGOALS),clean)
	@ make --no-print-directory -C $(LIB_DIR) clean
	@echo "==========$(CYAN1)MLX$(D_COLOR)==========\n"
	@if [ -d "$(MLX_DIR)" ]; then \
		make --no-print-directory -C $(MLX_DIR) clean $(SILENCE); \
		rm -rf $(MLX_DIR); \
		echo "$(RED1)$(DELETED)$(D_COLOR)\n"; \
	else \
		echo "$(PINK1)La suppression du dossier $(MIN) est impossible car il n'existe pas !$(D_COLOR)\n"; \
	fi
endif
ifeq ($(MAKECMDGOALS),clean_lib)
	@ make --no-print-directory -C $(LIB_DIR) clean
endif

fclean : clean
	@ make --no-print-directory -C $(LIB_DIR) fclean
	@echo "==========$(CYAN1)EXEC$(D_COLOR)===========\n"
	@rm -rf $(NAME)
	@echo "$(RED1)$(DELETED)$(D_COLOR)\n"

re : fclean all

.PHONY : all, clean, fclean, re, bonus