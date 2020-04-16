##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile for the minishell1
##

SRC 	=	src/tools.c\
			src/str_to_word_tab.c\
			src/solver_algo.c\
			src/main.c

OBJ 	=	$(SRC:.c=.o)

NAME 	=	solver

CFLAGS += -W -Wall -Wextra -pedantic -I./include

all:	$(NAME)

$(NAME):	$(OBJ)
		@echo "Compiling..."
		@$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

%.o : %.c
		@echo "Compiling $@..."
		@$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@echo "removing *.o..."
	@rm -f src/*.o
	@rm -f *.o

fclean:	clean
	@echo "removing $(NAME)..."
	@rm -f $(NAME)

re: 	fclean all

debug:	CFLAGS += -g3
debug:	fclean all