/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-1-minishell1-suleman.maqsood
** File description:
** old pwd
*/

#include <stdlib.h>
#include "my.h"

static int make_old_pwd(int l, env_t *en)
{
    int i = 0;
    en->env[l][i] = 'O';
    i++;
    en->env[l][i] = 'L';
    i++;
    en->env[l][i] = 'D';
    i++;
    en->env[l][i] = 'P';
    i++;
    en->env[l][i] = 'W';
    i++;
    en->env[l][i] = 'D';
    i++;
    en->env[l][i] = '=';
    i++;
    return 0;
}

int put_old_pwd(env_t *en)
{
    int l = find_old_pwd(en->env);
    int c = 0;
    while (en->env[l][c] != 0) {
        if (en->env[l][c] == '/')
            break;
        c++;
    }
    free(en->env[l]);
    en->env[l] = malloc(sizeof(char) * c + (my_strlen(en->old_pwd)));
    make_old_pwd(l, en);
    for (int i = 0; en->old_pwd[i] != 0; i++) {
        en->env[l][c] = en->old_pwd[i];
        c++;
    }
    en->env[l][c] = 0;
    return 0;
}
