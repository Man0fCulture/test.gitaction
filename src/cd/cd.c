/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-1-minishell1-suleman.maqsood
** File description:
** cd
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

static int add_new_pwd_in_env(char **env, char *fon, int l,env_t *en)
{
    int ligne = find_pwd(env);
    int nbc = 4;
    int c = 0;
    char buf[5000];
    getcwd(buf, 5000);
    en->env[l] = malloc(sizeof(char) * nbc + (my_strlen(buf)));
    for (int i = 0; env[ligne][i] != '='; i++) {
        en->env[l][c] = env[ligne][i];
        c++;
    }
    en->env[l][c] = '=';
    c++;
    for (int i = 0; buf[i] != 0; i++) {
        en->env[l][c] = buf[i];
        c++;
    }
    en->env[l][c] = 0;
    return 0;
}

static int copy_old_pwd(int i, int l, int c, env_t *en)
{
    en->old_pwd = malloc(sizeof(char) * (my_strlen(en->env[l]) - c));
    while (en->env[l][c] != 0) {
        en->old_pwd[i] = en->env[l][c];
        c++;
        i++;
    }
    en->old_pwd[i] = 0;
    return 0;
}

int create_cd(char *fon, char **env, env_t *en)
{
    int l = find_pwd(en->env);
    int c = 0;
    int i = 0;
    if (en->env[l] == NULL)
        create_new_env_for_cd(en);
    while (en->env[l][c] != 0) {
        if (en->env[l][c] == '/')
            break;
        c++;
    }
    if (chdir(fon) == -1) {
        write(1, fon, my_strlen(fon));
        write(1, ": No such file or directory.", 29);
        write(1, "\n", 1);
        return 1;
    }
    copy_old_pwd(i, l, c, en);
    add_new_pwd_in_env(env, fon, l, en);
    return 0;
}
