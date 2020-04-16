##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile for compile matchstick
##

CFLAGS	+= -I./include

SRC		=		src/main.c\
				src/map.c\
				src/turn_game.c\
				src/tools.c\
				src/use_fonc.c

OBJ		=		$(SRC:.c=.o)

NAME	=		matchstick

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ)

clean:	
		rm -f src/*.o

fclean:	clean
		rm -f $(NAME)

re:		fclean all