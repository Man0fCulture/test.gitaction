/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-1-minishell2-suleman.maqsood
** File description:
** redirection
*/

#include <stdio.h>
#include <unistd.h>
#include "my.h"

static int check_next(char **fon, char **env, env_t *en, fon_t *tmp)
{
    if (tmp->next->next == NULL) {
        write(1, "Missing name for redirect.\n", 28);
        return 1;
    }
    return 0;
}

static int redirection_right(char **fon, char **env, env_t *en, fon_t *tmp)
{
    if (check_next(fon, env, en, tmp) == 1)
        return 1;
    if (my_strlen(tmp->next->fon[0]) == 2) {
        double_right(fon, env, en, tmp);
        return 1;
    }
    check_fonction_right(fon, env, en, tmp);
    return 0;
}

static int redirection_pipe(char **fon, char **env, env_t *en, fon_t *tmp)
{
    if (tmp->next->next == NULL) {
        write(1, "Invalid null command.\n", 23);
        return 1;
    }
    check_fonction_pipe(fon, env, en, tmp);
    return 0;
}

int special_direction(char **fon, char **env, env_t *en, fon_t *tmp)
{
    if (tmp->next != NULL) {
        if (tmp->next->fon[0][0] == '>') {
            redirection_right(fon, env, en, tmp);
            return 1;
        }
        if (tmp->next->fon[0][0] == '|') {
            redirection_pipe(fon, env, en, tmp);
            return 1;
        }
    }
    return 0;
}
