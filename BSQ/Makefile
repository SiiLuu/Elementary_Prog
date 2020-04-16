##
## Makefile for BSQ.c
##

SRC		=	bsq.c\
			use_fonc.c\
			use_fonc2.c

OBJ		=	$(SRC:.c=.o)

NAME		=	bsq

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(SRC)

clean:
	rm -f *.o

fclean:
	rm -f $(NAME)

re:		fclean all