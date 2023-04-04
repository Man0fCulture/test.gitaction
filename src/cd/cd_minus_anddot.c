/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-1-minishell1-suleman.maqsood
** File description:
** cd minus and cd dot dot
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

static int make_pwd(int l, char *copy_old, env_t *en)
{
    int i = 0;
    en->env[l][i] = 'P';
    i++;
    en->env[l][i] = 'W';
    i++;
    en->env[l][i] = 'D';
    i++;
    en->env[l][i] = '=';
    i++;
    for (int c = 0; copy_old[c] != 0; c++) {
        en->env[l][i] = copy_old[c];
        i++;
    }
    en->env[l][i] = 0;
    return 0;
}

static int add_new_pwd_in_env(char *copy_old, int l, env_t *en)
{
    int c = 0;
    while (en->env[c] != 0) {
        if (en->env[l][c] == '/')
            break;
        c++;
    }
    free(en->env[l]);
    en->env[l] = malloc(sizeof(char) * (my_strlen(copy_old) + c));
    make_pwd(l, copy_old, en);
    return 0;
}

static int copy_old_pwd(int l, char *copy_old, env_t *en)
{
    int i = 0;
    int c = 0;
    while (en->env[c] != 0) {
        if (en->env[l][c] == '/')
            break;
        c++;
    }
    en->old_pwd = malloc(sizeof(char) * (my_strlen(en->env[l]) - c));
    while (en->env[l][c] != 0) {
        en->old_pwd[i] = en->env[l][c];
        c++;
        i++;
    }
    en->old_pwd[i] = 0;
    add_new_pwd_in_env(copy_old, l, en);
    return 0;
}

int cd_minus(env_t *en)
{
    char *copy_old = malloc(sizeof(char) * my_strlen(en->old_pwd));
    int l = find_pwd(en->env);
    int save = 0;
    int i = 0;
    if (en->env[l] == NULL)
        create_new_env_for_cd(en);
    while (en->old_pwd[i] != 0) {
        copy_old[i] = en->old_pwd[i];
        i++;
    }
    copy_old[i] = 0;
    chdir(en->old_pwd);
    free(en->old_pwd);
    copy_old_pwd(l, copy_old, en);
    return 0;
}
