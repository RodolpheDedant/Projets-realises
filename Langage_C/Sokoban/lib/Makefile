##
## EPITECH PROJECT, 2020
## delivery
## File description:
## Makefile
##

SRC     =		my_printf.c			\
				my_all_put.c		\
				flag_i_d_s_c_u.c	\
				my_strlen.c			\
				my_strcpy.c

OBJ     =       $(SRC:.c=.o)

NAME    =       libmy.a

all:    $(NAME)

$(NAME):        $(OBJ)
	ar rc   $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: 	clean
	rm -f $(NAME)

re:	fclean all