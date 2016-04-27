##
## Makefile for colle3 in /home/Sinjide/rendu/Piscine_C_colles-Semaine_03
## 
## Made by Nicolas Guillon
## Login   <Sinjide@epitech.net>
## 
## Started on  Fri Oct 23 10:41:45 2015 Nicolas Guillon
## Last update Wed Apr 27 13:46:56 2016 remi pastor
##

CC	= gcc -g3 -O3

RM	= rm -f

NAME	= generator_sudoku

SRCS	= main.c \
	  check_gen.c \
	  empty_line.c \
	  verif_gen.c \
	  resolve_gen.c \
	  simple_generator.c

OBJ	= $(SRCS:.c=.o)

all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) -Wall -pedantic -W -Wextra -Werror -ansi

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
