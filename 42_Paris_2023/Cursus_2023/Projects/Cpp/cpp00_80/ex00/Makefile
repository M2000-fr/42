# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mechard <mechard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/22 13:47:46 by mechard           #+#    #+#              #
#    Updated: 2025/03/21 15:28:20 by mechard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#==================VAR_GBL==================

NAME			= megaphone
INC				= inc/

#===================FLAG====================

CXXFLAGS			= -Wall -Wextra -Werror -std=c++98 -g3
CXX					= c++ $(CXXFLAGS) $(HEADERS)

#===================OTHERS==================

SUCCESS			= ✅
TELECHARGEMENT	= 🔽🔁
DL_FINISH		= 🔽✅
DELETED			= 💥
SILENCE			= > /dev/null 2>&1
MAKE			= make --no-print-directory -C ./
FIN				= =================$(GREEN1)END$(D_COLOR)=================\n

#==================SOURCES==================

SRCS			= megaphone.cpp

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

all : $(NAME)

$(NAME) : $(SRCS)
ifeq ($(filter-out all $(NAME), $(MAKECMDGOALS)), )
	@$(MAKE) begin ARG3="$(MAKECMDGOALS)"
endif
	@-$(CXX) $(SRCS) -o $(NAME)
	@if [ ! -s res_cmp ]; then \
		rm -rf res_cmp; \
	fi
	@if [ ! -s res_cmp ]; then \
		echo "|  =======$(YELLOW1)CPP00$(D_COLOR)========             |"; \
		echo "|                                   |"; \
		echo "|$(NAME)                      : $(GREEN1)$(SUCCESS)$(D_COLOR)|"; \
	elif [ -s res_cmp ]; then \
		echo "|                                   |"; \
		echo "|$(RED1)Erreur de compilation !!$(D_COLOR)           |"; \
		echo "|$(YELLOW1)Consultez les commandes \"make cmp\" $(D_COLOR)|"; \
		echo "|$(YELLOW1)ou le fichier \"cmp_res\"            $(D_COLOR)|"; \
		echo "|$(YELLOW1)pour plus de details !$(D_COLOR)             |"; \
		echo "|                                   |"; \
	fi

ifeq ($(filter-out all $(NAME) re, $(MAKECMDGOALS)), )
	@$(MAKE) end
endif

$(LIB_A) :
	@make --no-print-directory -C $(LIB_DIR) $(LIB) 

clean :
ifneq ($(filter-out $(COMPI),$(MAKECMDGOALS)),)
	@$(MAKE) begin ARG3="$(MAKECMDGOALS)"
endif

ifeq ($(MAKECMDGOALS), clean)
	@$(MAKE) end
endif

fclean : clean
	@if [ -f "$(LIB_A)" ]; then \
		$(MAKE)$(LIB_DIR) fclean $(SILENCE); \
		echo "|$(LIB)                      : $(RED1)$(DELETED)$(D_COLOR)  |"; \
	fi
	@if [ -f "$(NAME)" ]; then \
		rm -rf $(NAME) $(SILENCE); \
		echo "|$(NAME)                    : $(RED1)$(DELETED)$(D_COLOR)  |"; \
	fi

ifeq ($(MAKECMDGOALS), fclean)
	@$(MAKE) end
else
	@echo "|                                   |"	
endif

re : fclean all

.PHONY : all, clean, fclean, re

#________OTHER_RULES___________

begin :
	@if [ -z "$(ARG3)" ]; then upper_makecmd="\" \""; else upper_makecmd=$$(echo $(ARG3) | tr 'a-z' 'A-Z'); fi; \
	len=$$(echo -n "$$upper_makecmd" | wc -c); \
	eq_len=$$(( (37 - len) / 2 )); \
	left_len=$$(( eq_len )); \
	right_len=$$(( 37 - len - left_len )); \
	printf "\n"; \
	for _ in $$(seq 1 $$left_len); do printf "="; done; \
	printf "$(PINK1)$$upper_makecmd$(D_COLOR)"; \
	for _ in $$(seq 1 $$right_len); do printf "="; done; \
	printf "\n"; \
	printf "|                                   |\n"

end :
	@printf "|                                   |\n"
	@echo "$(FIN)"
