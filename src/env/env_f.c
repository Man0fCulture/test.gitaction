/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-1-minishell1-suleman.maqsood
** File description:
** fonction env
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int create_new_env_for_cd(env_t *en)
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
    en->env = new_env;
    en->env[en->nbl_denv] = NULL;
    return 0;
}

int free_ele_env(env_t *en)
{
    free(en->env);
    return 0;
}

int print_env(env_t *en)
{
    if (en->env == NULL) {
        return 0;
    }
    for (int l = 0; en->env[l] != NULL; l++) {
        my_putstr(en->env[l]);
        write(1, "\n", 1);
    }
    return 0;
}
