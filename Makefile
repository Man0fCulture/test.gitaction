##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile
##

SRC	=	src/error.c	\
		src/open_patern.c	\
		src/create_square.c	\
		src/find_square.c	\
		src/map_to_number.c	\
		src/my_putstr.c	\
		src/my_getnbr.c	\
		src/count_nbc_andnbl.c	\
		src/my_new_bsq.c	\
		src/main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	bsq

CFLAGS	=	-W -Wall -Wextra -I include -g3

all:	$(OBJ)
		$(CC) $(OBJ) -o $(NAME)

clean:
		$(RM) $(OBJ)
		$(RM) *~

fclean:	clean
		$(RM) $(NAME)

re: fclean all

.PHONY:	all fclean clean
