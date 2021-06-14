##
## EPITECH PROJECT, 2020
## delivery
## File description:
## Makefile
##

SRC     =		main.c	\
				src/matchstick.c	\
				src/map.c			\
				src/game.c			\
				src/line.c			\
				src/match.c			\
				src/ia.c			\
				src/check.c

OBJ     =       $(SRC:.c=.o)

NAME    =		matchstick

CPFLAGS	=	-Wall -Wextra -Werror

CPPFLAGS = -I../include/ -I./include/

CC		= gcc -g

all:	$(NAME)

lib:
	$(MAKE) -C lib

$(NAME): 	lib      $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CPPFLAGS) $(CPFLAGS) -L./lib -lmy

clean:
	rm -f $(OBJ)
	$(MAKE) clean -C lib

fclean: 	clean
	rm -f $(NAME)
	$(MAKE) fclean -C lib

re:	fclean all
	$(MAKE) re -C lib

.PHONY: all lib clean fclean re