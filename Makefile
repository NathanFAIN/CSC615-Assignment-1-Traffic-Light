#************************************************************** * Class: CSC-615-01 Spring 2020
# Name: Nathan Fain
# Student ID: 922295956
# Github ID: NathanFAIN
# Project: Assignment 1 - Traffic Light
# File: Makefile
#
# Description:
# **************************************************************/

CC	=	gcc

SRC	=	./src/main.c 					\

OBJ	=	$(SRC:.c=.o)

NAME =	binary

CFLAGS	=	-I ./include/		\
			-W					\
			-Wextra				\
			-Wall				\

RM = rm -f

all: $(OBJ)
		@ echo "\033[1;36m[ FILES COMPILED ] \033[0m \033[1;34m$(words $(SRC))\033[0m"
		@ $(CC) $(OBJ) $(CFLAGS) -o $(NAME)
		@ echo "\033[1;34mBinary : \033[1;32m$(NAME)\033[1;34m created sucesfully.\033[0m"

clean:
		@ echo "\033[3;31mRemoving: \033[0m"
		@ echo "\033[3;31m$(OBJ)\033[0m" | tr ' ' '\n'
		@ $(RM) $(OBJ)

fclean:	clean
		@ echo "\033[3;31m./$(NAME)\033[0m"
		@ $(RM) $(NAME)

re: fclean all

%.o:	%.c
	@ echo "\033[1;34m[ OK ]\033[0m Compiling" $<
	@ $(CC) -o $@ -c $< $(CFLAGS)

.PHONY: all clean fclean re