# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tarchen <tarchen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 14:35:50 by tarchen           #+#    #+#              #
#    Updated: 2017/09/23 08:17:32 by tarchen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

DIR = ./objets

CC = gcc


CFLAGS =	-Wall \
			-Wextra \
			-Werror \
			-g \
			-g3 \

ITOA_DIR = ./itoa/
ITOA_SRCS = \
		ft_itoa_char.c \
		ft_itoa_float.c \
		ft_itoa_int.c \
		ft_itoa_long.c \
		ft_itoa_long_double.c \
		ft_itoa_long_long.c \
		ft_itoa_short.c \
		ft_itoa_size_t.c \
		ft_itoa_uintmax_t.c \
		ft_itoa_uintptr_t.c \
		ft_itoa_intmax_t.c \
		ft_itoa_intptr_t.c \
		ft_itoa_unsigned.c \
		ft_itoa_unsigned_char.c \
		ft_itoa_unsigned_long.c \
		ft_itoa_unsigned_long_long.c \
		ft_itoa_unsigned_short.c \

ITOA_OBJS = $(ITOA_SRCS:.c=.o)
ITOA_DIRS = $(addprefix objets/, $(ITOA_SRCS:.c=.o))
ITOA = $(addprefix $(ITOA_DIR), $(ITOA_SRCS))
SRC = \
		error.c\
		ft_strbrut.c\
		ft_atof.c \
		ft_atod.c \
		ft_atoi.c \
		ft_atoi_char.c \
		ft_atoi_lld.c \
		ft_atoi_start.c \
		ft_bintohex.c \
		ft_bzero.c \
		ft_cat_char.c \
		ft_hextobin.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_itoa_base.c \
		ft_itoa_base_up.c \
		ft_itoa_base_u.c \
		ft_itoa_base_u_up.c \
		ft_itoa_base_u_lld.c \
		ft_itoa_base_u_lld_up.c \
		ft_itoa_base_u_ld.c \
		ft_itoa_base_u_ld_up.c \
		ft_itoa_base_lld.c \
		ft_itoa_base_lld_up.c \
		ft_itoa_base_ld.c \
		ft_itoa_base_ld_up.c \
		ft_memalloc.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memdel.c \
		ft_memmove.c \
		ft_memset.c \
		ft_nbrlen.c \
		ft_print_tabint.c \
		ft_print_tabstr.c \
		ft_power.c \
		ft_putchar.c \
		ft_putchar_fd.c \
		ft_putdbl.c \
		ft_putdbl_fd.c \
		ft_putendl.c \
		ft_putendl_fd.c \
		ft_putnbr.c \
		ft_putnbr_base.c \
		ft_putnbr_fd.c \
		ft_putnbr_ll.c \
		ft_putnbr_u.c \
		ft_putstr.c \
		ft_putstr_fd.c \
		ft_sort_nparams.c \
		ft_sort_params.c \
		ft_stradd.c \
		ft_strcat.c \
		ft_strchr.c \
		ft_strclr.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strcut.c \
		ft_strdel.c \
		ft_strdup.c \
		ft_strealloc.c \
		ft_strequ.c \
		ft_strfind.c \
		ft_strfind_ls_char.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlen.c \
		ft_strncat.c \
		ft_strncmp.c \
		ft_strncpy.c \
		ft_strnequ.c \
		ft_strnew.c \
		ft_strnlen.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strrev.c \
		ft_strsplit.c \
		ft_strstr.c \
		ft_strsub.c \
		ft_strtrim.c \
		ft_tolower.c \
		ft_toupper.c \
		get_next_line.c \
		gnl_stdout.c \
		get_width_term.c \
		try_malloc.c \
		ft_putchar_tab.c \
		ft_strchar.c \
		ft_strinsert.c \
		ft_strjoin_ap.c \
		ft_putwchar.c \
		ft_wchartostr.c \

OBJ = $(SRC:.c=.o)
OBJ_DIR = $(addprefix objets/, $(OBJ))

all: $(NAME)

lib: re
	@/bin/rm -f $(OBJ) libft.h.gch

$(NAME):
	@$(CC) $(CFLAGS) -c $? $(SRC) $(ITOA)
	@ar rc $(NAME) $? $(OBJ) $(ITOA_OBJS)
	@ranlib $(NAME)
	@mkdir -p objets
	@mv $(OBJ) ./objets
	@mv $(ITOA_OBJS) ./objets
	@echo "\033[32mBuilt library.\033[0m"

clean:
	@/bin/rm -rf $(DIR) libft.h.gch
	@echo "\033[32mCleaned up object files.\033[0m"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "\033[32mCleaned up compiled files.\033[0m"

re: fclean all

.PHONY: all lib clean fclean re
