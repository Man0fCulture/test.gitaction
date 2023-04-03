/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-1-minishell1-suleman.maqsood
** File description:
** cd home
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

static int make_pwd(int l, char *buf, env_t *en)
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
    for (int c = 0; buf[c] != 0; c++) {
        en->env[l][i] = buf[c];
        i++;
    }
    en->env[l][i] = 0;
    return 0;
}

static int go_home(int ligne, int l, env_t *en)
{
    int c = 0;
    int i = 0;
    char *buf;
    free(en->env[l]);
    while (en->env[ligne][c] != 0) {
        if (en->env[ligne][c] == '/')
            break;
        c++;
    }
    buf = malloc(sizeof(char) * my_strlen(en->env[ligne]) - c);
    while (en->env[ligne][c] != 0) {
        buf[i] = en->env[ligne][c];
        c++;
        i++;
    }
    buf[i] = 0;
    chdir(buf);
    en->env[l] = malloc(sizeof(char) * i + 4);
    make_pwd(l, buf, en);
    return 0;
}

int cd_to_home(env_t *en)
{
    int l = find_pwd(en->env);
    int ligne = find_home(en->env);
    int c = 0;
    int i = 0;
    if (en->env[l] == NULL)
        create_new_env_for_cd(en);
    while (en->env[l][c] != 0) {
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
    go_home(ligne, l, en);
    return 0;
}
