/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-1-minishell1-suleman.maqsood
** File description:
** add new line for env
*/

#include <stdlib.h>
#include <my.h>

static char **save_new_line(char **new_env, int c, env_t *en)
{
    int nbc = my_strlen(en->fon[1]);
    int l = en->nbl_denv - 1;
    int i = 0;
    nbc += my_strlen(en->fon[2]);
    new_env[l] = malloc(sizeof(char) * nbc);
    while (en->fon[1][c] != 0) {
        new_env[l][c] = en->fon[1][c];
        c++;
    }
    new_env[l][c] = '=';
    c++;
    while (en->fon[2][i] != 0) {
        new_env[l][c] = en->fon[2][i];
        c++;
        i++;
    }
    new_env[l][c] = 0;
    en->env = new_env;
    return en->env;
}

int create_new_env(env_t *en)
{
    int c = 0;
    int colo = 0;
    int i = 0;
    char **new_env = malloc(sizeof(char *) * en->nbl_denv + 1);
    en->nbl_denv++;
    for (int ligne = 0; en->env[ligne]; ligne++) {
        new_env[ligne] = malloc(sizeof(char) * (my_strlen(en->env[ligne])));
        while (en->env[ligne][c] != 0) {
            new_env[ligne][c] = en->env[ligne][c];
            c++;
    }
    new_env[ligne][c] = 0;
    c = 0;
    }
    free_ele_env(en);
    save_new_line(new_env, colo, en);
    en->env[en->nbl_denv] = NULL;
    return 0;
}

static char **save_new_line_void(char **new_env, int c, int i, env_t *en)
{
    int nbc = my_strlen(en->fon[1]);
    int l = en->nbl_denv - 1;
    nbc += 1;
    new_env[l] = malloc(sizeof(char) * nbc);
    while (en->fon[1][c] != 0) {
        new_env[l][c] = en->fon[1][c];
        c++;
    }
    new_env[l][c] = '=';
    c++;
    new_env[l][c] = 0;
    en->env = new_env;
    return en->env;
}

int create_new_env_void(env_t *en)
{
    int c = 0;
    int colo = 0;
    int i = 0;
    char **new_env = malloc(sizeof(char *) * en->nbl_denv + 1);
    en->nbl_denv++;
    for (int ligne = 0; en->env[ligne]; ligne++) {
        new_env[ligne] = malloc(sizeof(char) * (my_strlen(en->env[ligne])));
        while (en->env[ligne][c] != 0) {
        new_env[ligne][c] = en->env[ligne][c];
        c++;
    }
    new_env[ligne][c] = 0;
    c = 0;
    }
    free_ele_env(en);
    save_new_line_void(new_env, colo, i, en);
    en->env[en->nbl_denv] = NULL;
    return 0;
}
