##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## 
##

SRC =	src/check_end.c				\
		src/initiation.c			\
		src/player_move.c			\
		src/my_sokoban.c			\
		error_check/arg_error.c		\
		error_check/char_error.c	\
		main.c

OBJ = $(SRC:.c=.o)

CFLAGS = -I./include -lncurses

NAME = my_sokoban

$(NAME) :	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

all: $(NAME)

clean :
		$(RM) -f *.c~
		$(RM) $(OBJ)

fclean :clean
		$(RM) $(NAME)

re : fclean all