##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile for the minishell1
##

all:
		@echo "Compiling generator binary..."
		@make -C generator
		@echo "Compiling solver binary..."
		@make -C solver

clean:
	@echo "removing *.o of the generator folder..."
	@rm -f generator/src/*.o
	@echo "removing *.o of the solver folder..."
	@rm -f solver/src/*.o

fclean:	clean
	@echo "removing generator binary..."
	@rm -f generator/generator
	@echo "removing solver binary..."
	@rm -f solver/solver

re: 	fclean all