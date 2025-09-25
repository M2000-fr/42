NAME		= rush-02

CFLAGS		= -Wall -Wextra -Werror

INC			= -I ./includes
SRC			= ./srcs/*.c
OBJ			= ./*.o
PATH_OBJ	= ./objs/*.o

all: $(NAME)

$(NAME): obj $(OBJ)
	@echo "\n----------------------\033[34mCompilation\033[0m----------------------\n"
	@echo "                  compilation des .c \033[32mOK\033[0m\n"
	@cc -o $(NAME) $(PATH_OBJ)
	@echo "                compilation du rush-02 \033[32mOK\033[0m\n"

$(OBJ): $(SRC)
	@cc -c $(SRC) $(INC) 
	@mv $(OBJ) ./objs

obj:
	@mkdir objs

clean:
	-@rm -f *.o
	-@rm -rf objs
	@echo "\n----------------------\033[33mFolder Clean\033[0m----------------------\n"
	@echo "                Fichiers objets \033[31mSUPPRIME\033[0m\n"

fclean: clean
	-@rm -f $(NAME)
	@echo "                     rush-02 \033[31mSUPPRIME\033[0m"

re: fclean all