/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-1-minishell2-suleman.maqsood
** File description:
** write error
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

static int check_alphabetise(env_t *en)
{
    int c = 0;
    while (en->fon[1][c] != 0) {
        if ((en->fon[1][c] < 'a' || en->fon[1][c] > 'z') &&
        (en->fon[1][c] < 'A' || en->fon[1][c] > 'Z') &&
        (en->fon[1][c] < '0' || en->fon[1][c] > '9') &&
        en->fon[1][c] != '_') {
            write(1,
            "setenv: Variable name must contain alphanumeric characters.\n"
            , 60);
            en->one = 1;
            return 1;
        }
        c++;
    }
    return 0;
}

int second_time(env_t *en)
{
    if (check_alphabetise(en) == 1)
        return 0;
    if (en->fon[2] == NULL) {
            set_env_void(en);
            return 0;
        }
        if (en->fon[3] != NULL) {
            write(1, "setenv: Too many arguments.\n", 29);
            en->one = 1;
            return 0;
        }
    return 1;
}

int help_check_setenv(char **env, env_t *en)
{
    if (en->fon[1] == NULL) {
        print_env(en);
        return 0;
    }
    if ((en->fon[1][0] < 'a' || en->fon[1][0] > 'z') &&
    (en->fon[1][0] < 'A' || en->fon[1][0] > 'Z') &&
        en->fon[1][0] != '_') {
        write(1, "setenv: Variable name must begin with a letter.\n", 49);
        en->one = 1;
        return 0;
    }
    if (second_time(en) == 0) {
        return 0;
    }
    set_env(en);
    return 0;
}
