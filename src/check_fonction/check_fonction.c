/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-1-minishell1-suleman.maqsood
** File description:
** check if the fonction is real
*/

#include <unistd.h>
#include "my.h"

static int check_setenv(char **env, env_t *en)
{
    if (en->fon[0][0] == 's' && en->fon[0][1] == 'e' && en->fon[0][2] == 't' &&
    en->fon[0][3] == 'e' && en->fon[0][4] == 'n' && en->fon[0][5] == 'v') {
        if (help_check_setenv(env, en) == 0)
            return 0;
    }
    return 1;
}

static int env_check(env_t *en)
{
    if (en->fon[0][0] == 'e' && en->fon[0][1] == 'n' && en->fon[0][2] == 'v') {
        if (en->fon[1] != NULL) {
            write(1, "env: Too many arguments.\n", 26);
            return 0;
        }
        print_env(en);
        return 0;
    }
    return 1;
}

int check_unsetenv(env_t *en, int *exit)
{
    if (en->fon[0][0] == 'u' && en->fon[0][1] == 'n' && en->fon[0][2] == 's' &&
    en->fon[0][3] == 'e' && en->fon[0][4] == 't' && en->fon[0][5] == 'e' &&
    en->fon[0][6] == 'n' && en->fon[0][7] == 'v') {
        if (en->fon[1] == NULL) {
            my_putstr("unsetenv: Too few arguments.\n");
            en->one = 1;
            *exit = 1;
            return 1;
        }
        un_set_env(en);
        return 0;
    }
    return 1;
}

int check_cd(char **env, env_t *en)
{
    if (en->fon[0][0] == 'c' && en->fon[0][1] == 'd') {
        if (en->fon[1] == NULL || en->fon[1][0] == '~') {
            cd_to_home(en);
            return 0;
        }
        if (en->fon[1][0] == '-' && en->old_pwd != NULL) {
            cd_minus(en);
            return 0;
        }
        create_cd(en->fon[1], env, en);
        return 0;
    }
    return 1;
}

int check_fonction(char **env, env_t *en)
{
    int exit = 0;
    if (check_cd(env, en) == 0)
        return 0;
    if (env_check(en) == 0)
        return 0;
    if (check_setenv(env, en) == 0) {
        if (en->one == 1)
            return 1;
        return 0;
    }
    if (check_unsetenv(en, &exit) == 0)
        return 0;
    if (exit == 1)
        return 0;
    return 1;
}
