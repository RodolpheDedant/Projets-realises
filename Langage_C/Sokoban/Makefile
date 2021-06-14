##
## EPITECH PROJECT, 2020
## delivery
## File description:
## Makefile
##

SRC     =		main.c				\
				src/my_sokoban.c 	\
				src/game.c			\
				src/tool.c			\
				src/tool_bis.c		\
				src/move_up.c		\
				src/move_down.c 	\
				src/move_right.c 	\
				src/move_left.c		\
				src/refresh_map.c	\
				src/tool_third.c

OBJ     =       $(SRC:.c=.o)

NAME    =       my_sokoban

CPFLAGS	=	-Wall -Wextra -Werror

CPPFLAGS = -I../include/ -I./include/

all:	$(NAME)

lib:
	$(MAKE) -C lib

$(NAME): 	lib      $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CPPFLAGS) $(CPFLAGS) -L./lib -lmy -lncurses -g

clean:
	rm -f $(OBJ)
	$(MAKE) clean -C lib

fclean: 	clean
	rm -f $(NAME)
	$(MAKE) fclean -C lib

re:	fclean all
	$(MAKE) re -C lib

.PHONY: all lib clean fclean re