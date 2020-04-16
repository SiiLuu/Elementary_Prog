##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile for the minishell1
##

SRC 	=	src/main.c\
			src/parsing.c\
			src/basic_map_parsing.c\
			src/wrong_anthill.c\
			src/wrong_anthill_2.c\
			src/coord_room.c\
			src/input_in_array.c\
			src/ants.c

OBJ 	=	$(SRC:.c=.o)

NAME 	=	lem_in

CFLAGS += -W -Wall -Wextra -g3 -pedantic -I./include

LFLAGS = -L./lib/my -lmy

all:	$(NAME)

$(NAME):	$(OBJ)
		make -C lib/my
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LFLAGS)
clean:
	rm -f lib/my/*.o
	rm -f src/*.o
	rm -f lib/my/libmy.a
	rm -f *.o

fclean:	clean
	rm -f $(NAME)

re: 	fclean all