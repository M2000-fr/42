# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maechard <maechard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 11:35:46 by maechard          #+#    #+#              #
#    Updated: 2018/04/18 18:14:08 by maechard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -Wall -Wextra -Werror -I ./includes/

ALLC = 	ft_strlen.c \
		ft_strdup.c \
		ft_strcpy.c\
	  	ft_strncpy.c \
	  	ft_strcat.c \
	  	ft_strncat.c \
	  	ft_strlcat.c \
	  	ft_strchr.c \
	  	ft_strrchr.c\
	  	ft_isalpha.c \
	  	ft_isdigit.c \
	  	ft_isalnum.c\
	  	ft_isascii.c \
	  	ft_isprint.c \
	  	ft_toupper.c \
	  	ft_tolower.c \
	  	ft_strstr.c \
	  	ft_memset.c \
	  	ft_bzero.c \
	  	ft_memcpy.c \
	  	ft_memccpy.c\
	  	ft_memmove.c \
	  	ft_memchr.c \
	  	ft_memcmp.c \
	  	ft_strcmp.c \
	  	ft_strncmp.c \
	  	ft_strnstr.c\
	  	ft_atoi.c \
	  	ft_memalloc.c \
	  	ft_memdel.c \
	  	ft_strnew.c \
	  	ft_strdel.c \
	  	ft_strclr.c \
	  	ft_striter.c \
	  	ft_striteri.c \
	  	ft_strmap.c \
	  	ft_strmapi.c \
	  	ft_strequ.c \
	  	ft_strnequ.c \
	  	ft_strsub.c \
	  	ft_strjoin.c \
	  	ft_strtrim.c \
	  	ft_strsplit.c \
	  	ft_itoa.c \
	  	ft_putchar.c \
	  	ft_putstr.c \
	  	ft_putendl.c \
	  	ft_putnbr.c \
	  	ft_putchar_fd.c \
	  	ft_putstr_fd.c \
	  	ft_putendl_fd.c \
	  	ft_putnbr_fd.c \
	  	ft_lstnew.c \
	  	ft_lstdelone.c \
	  	ft_lstdel.c \
	  	ft_lstadd.c \
	  	ft_lstiter.c \
	  	ft_lstmap.c \
		get_next_line.c
SRC = $(addprefix src/, $(ALLC))

DIR = /objets
OBJ = $(ALLC:.c=.o)
OBJ_DIR = $(addprefix objets/, $(OBJ))

all: $(NAME)

lib: re
	@/bin/rm -f $(OBJ)

$(NAME):
	@$(CC) $(CFLAGS) -c $? $(SRC)
	@mkdir -p objets
	@mv $(OBJ) objets
	@ar rc $(NAME) $? $(OBJ_DIR)
	@ranlib $(NAME)
	@echo "<--------------------LIBFT-------------------->"
	@echo "\033[32mBuilt library of libft.\033[0m"

clean:
	@echo "<--------------------LIBFT-------------------->"
	@/bin/rm -rf $(DIR)
	@echo "\033[32mCleaned up object files.\033[0m"

fclean: clean
	@echo "<--------------------LIBFT-------------------->"
	@/bin/rm -f $(NAME)
	@echo "\033[32mCleaned up compiled files.\033[0m"

re: fclean all

.PHONY: all lib clean fclean re
