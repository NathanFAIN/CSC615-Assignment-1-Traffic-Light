# ************************************************************** * Class: CSC-615-01 Spring 2020
# Name: Nathan Fain
# Student ID: 922295956
# Github ID: NathanFAIN
# Project: Assignment 1 - Traffic Light
# File: Makefile
#
# Description:
# **************************************************************

CC	=	gcc

SRC1	=	./src/assignment1wpi/main.c	\

SRC2	=	./src/assignment1b/main.c	\

OBJ1	=	$(SRC1:.c=.o)
OBJ2	=	$(SRC2:.c=.o)

NAME1 =	assignment1wpi
NAME2 =	assignment1b

CFLAGS	=	-I ./include/	\
			-W				\
			-Wextra			\
			-Wall			\
			-lwiringPi		\

RM = rm -f

all: assignment1wpi assignment1b

$(NAME1): $(OBJ1)
		@ echo "\033[1;36m[ FILES COMPILED ] \033[0m \033[1;34m$(words $(SRC1))\033[0m"
		@ $(CC) $(OBJ1) $(CFLAGS) -o $(NAME1)
		@ echo "\033[1;34mBinary : \033[1;32m$(NAME)\033[1;34m created sucesfully.\033[0m"

$(NAME2): $(OBJ2)
		@ echo "\033[1;36m[ FILES COMPILED ] \033[0m \033[1;34m$(words $(SRC2))\033[0m"
		@ $(CC) $(OBJ2) $(CFLAGS) -o $(NAME2)
		@ echo "\033[1;34mBinary : \033[1;32m$(NAME)\033[1;34m created sucesfully.\033[0m"

clean:
		@ echo "\033[3;31mRemoving: \033[0m"
		@ echo "\033[3;31m$(OBJ1)\033[0m" | tr ' ' '\n'
		@ $(RM) $(OBJ1)
		@ echo "\033[3;31m$(OBJ2)\033[0m" | tr ' ' '\n'
		@ $(RM) $(OBJ2)

fclean:	clean
		@ echo "\033[3;31m./$(NAME1)\033[0m"
		@ $(RM) $(NAME1)
		@ echo "\033[3;31m./$(NAME2)\033[0m"
		@ $(RM) $(NAME2)

re: fclean all

%.o:	%.c
	@ echo "\033[1;34m[ OK ]\033[0m Compiling" $<
	@ $(CC) -o $@ -c $< $(CFLAGS)

.PHONY: all assignment1wpi assignment1b clean fclean re