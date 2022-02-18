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
		$(CC) $(OBJ1) $(CFLAGS) -o $(NAME1)

$(NAME2): $(OBJ2)
		$(CC) $(OBJ2) $(CFLAGS) -o $(NAME2)

clean:
		$(RM) $(OBJ1)
		$(RM) $(OBJ2)

fclean:	clean
		$(RM) $(NAME1)
		$(RM) $(NAME2)

re: fclean all

%.o:	%.c
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: all assignment1wpi assignment1b clean fclean re