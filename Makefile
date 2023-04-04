##
## EPITECH PROJECT, 2023
## B-PSU-200-PAR-2-1-minishell1-suleman.maqsood
## File description:
## makefile
##

SRC		=	src/env/unsetenv.c	\
			src/env/unsetenv_delete.c	\
			src/env/set_env_add_newline.c	\
			src/env/set_env.c	\
			src/env/env_f.c	\
			src/env/stock_env.c	\
			src/env/take_env.c	\
			src/env/set_env_void.c	\
			src/cd/find_in_env.c	\
			src/cd/cd_minus_anddot.c	\
			src/cd/cd_home.c	\
			src/cd/cd.c	\
			src/cd/old_pwd.c	\
			src/my_putstr.c	\
			src/check_fonction.c	\
			src/my_strlen.c	\
			src/str_to_word_array.c	\
			src/minishell.c	\
			src/main.c

OBJ		=	$(SRC:.c=.o)

NAME	=	libmy.a

NAMEE	=	mysh

CFLAGS	=	-W -Wall -Wextra -g3 -I include/

all:	$(OBJ)
		ar rc $(NAME) $(OBJ)
		gcc $(NAME) -o $(NAMEE)

clean:
		rm -f $(OBJ)
		rm -f *~

fclean:	clean
		rm -f $(NAME)
		rm -f $(NAMEE)

re: fclean all

.PHONY:	all fclean clean
