/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-1-minishell2-suleman.maqsood
** File description:
** double right redirection
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "my.h"

static int special_for_double_right_check_setenv(char **env, env_t *en,
fon_t *tmp)
{
    if (en->fon[0][0] == 's' && en->fon[0][1] == 'e' && en->fon[0][2] == 't' &&
    en->fon[0][3] == 'e' && en->fon[0][4] == 'n' && en->fon[0][5] == 'v') {
        if (special_double_right_help_check_setenv(env, en,
        tmp->next->next->fon[0])
        == 0)
            return 0;
    }
    return 1;
}

static int special_check_fonction(char **env, env_t *en, fon_t *tmp)
{
    int exit = 0;
    if (check_cd_right_right(env, en, tmp) == 0) {
        return 0;
    }
    if (special_for_double_right_env_check(en, tmp->next->next->fon[0]) == 0)
        return 0;
    if (special_for_double_right_check_setenv(env, en, tmp) == 0) {
        if (en->one == 1)
            return 1;
        return 0;
    }
    if (check_unsetenv(en, &exit) == 0) {
        already_exist_void_file(tmp->next->next->fon[0]);
        return 0;
    }
    if (exit == 1)
        return 0;
    return 1;
}

int double_right(char **fon, char **env, env_t *en, fon_t *tmp)
{
    if (special_check_fonction(env, en, tmp) == 0)
            return 0;
    if (en->one == 1) {
            en->one = 0;
            return 0;
        }
        if (exit_fon(env, en) == 0)
            return 0;
        special_for_double_right_my_execute(env, en, tmp);
    return 0;
}
