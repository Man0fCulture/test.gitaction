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
			src/env/write_error_setenv.c	\
			src/cd/find_in_env.c	\
			src/cd/cd_minus_anddot.c	\
			src/cd/cd_home.c	\
			src/cd/cd.c	\
			src/cd/old_pwd.c	\
			src/my_putstr.c	\
			src/writesymbole.c	\
			src/check_fonction/check_fonction.c	\
			src/my_strlen.c	\
			src/redirection/special_redirection.c	\
			src/redirection/create_void_file.c	\
			src/redirection/pipe/check_pipe.c	\
			src/redirection/right/right_check_fonction.c	\
			src/redirection/right/cd_setenv_env.c	\
			src/redirection/right/dual_operator/double_right.c	\
			src/redirection/right/dual_operator/already_exit_file.c	\
			src/redirection/right/dual_operator/cd_setenv_2_rightenv.c	\
			src/redirection/right/dual_operator/check_dual_right.c	\
			src/redirection/right/dual_operator/my_double_execute_special.c	\
			src/redirection/right/my_execute_special.c	\
			src/str_to_word_array/str_to_word_array.c	\
			src/str_to_word_array/count_letter.c	\
			src/str_to_word_array/my_special_strlen.c	\
			src/str_to_word_array/count_word.c	\
			src/minishell.c	\
			src/getline.c	\
			src/array_to_operator/array_to_word_operator.c	\
			src/array_to_operator/operator.c	\
			src/array_to_operator/for_op.c	\
			src/linked_list.c	\
			src/free_fon.c	\
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
