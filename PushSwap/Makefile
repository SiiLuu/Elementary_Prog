##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile for compile my_pushswap
##

SRC		=		src/my_pushswap.c\
				src/tools.c\
				src/list_gestion.c\
				src/sort.c

OBJ		=		$(SRC:.c=.o)

NAME	=		push_swap

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ)

clean:
		rm -f src/*.o

fclean:	clean
		rm -f $(NAME)

re:		fclean all