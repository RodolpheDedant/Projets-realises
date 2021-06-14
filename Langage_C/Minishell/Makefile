##
## EPITECH PROJECT, 2020
## delivery
## File description:
## Makefile
##

SRC     =		main.c		\
				src/choice.c \
				src/mysh.c		\
				src/commands.c	\
				src/unsetenv.c	\
				src/utils.c		\
				src/setenv.c	\
				src/my_exec.c	\
				src/utils_search.c	\
				src/cd.c			\
				src/chev.c

OBJ     =       $(SRC:.c=.o)

NAME    =       mysh

CFLAGS	=	-Wall -Wextra

CPPFLAGS =	-I../include/ -I./include/

all:	$(NAME)

lib:
	$(MAKE) -C lib/

$(NAME): 	lib      $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CPPFLAGS) $(CFLAGS) -L./lib -lmy


clean:
	rm -f $(OBJ)
	$(MAKE) clean -C lib/

fclean: 	clean
	rm -f $(NAME)
	$(MAKE) fclean -C lib/

re:	fclean all
	$(MAKE) re -C lib/

.PHONY: all lib clean fclean re