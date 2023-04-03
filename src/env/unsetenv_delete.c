/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-1-minishell1-suleman.maqsood
** File description:
** unsetenv delete one ele
*/

#include <stdlib.h>
#include "my.h"

static void save_last_ele(char **new_env, env_t *en)
{
    free_ele_env(en);
    en->env = new_env;
    en->env[en->nbl_denv] = NULL;
}

int delete_ele_env(int l, env_t *en)
{
    int c = 0;
    int colo = 0;
    int i = 0;
    int x = 0;
    char **new_env = malloc(sizeof(char *) * en->nbl_denv - 1);
    en->nbl_denv--;
    for (int ligne = 0; en->env[ligne]; ligne++) {
        if (ligne == l)
            continue;
        new_env[x] = malloc(sizeof(char) * (my_strlen(en->env[ligne])));
        while (en->env[ligne][c] != 0) {
            new_env[x][c] = en->env[ligne][c];
            c++;
    }
    new_env[x][c] = 0;
    c = 0;
    x++;
    }
    save_last_ele(new_env, en);
    return 0;
}
