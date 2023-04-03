/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-1-minishell1-suleman.maqsood
** File description:
** stock env in my struct
*/

#include <stdlib.h>
#include "my.h"

static void delete_mysh(char **env, int ligne, env_t *en)
{
    int c = 0;
    while (env[ligne][c] != 0) {
        if (env[ligne][c] == '.' && env[ligne][c + 1] == '/' &&
        env[ligne][c + 2] == 'm' && env[ligne][c + 3] == 'y' &&
        env[ligne][c + 4] == 's' && env[ligne][c + 5] == 'h')
            break;
        en->env[ligne][c] = env[ligne][c];
        c++;
    }
    en->env[ligne][c] = 0;
}

char **stock_env(char **env, env_t *en)
{
    en->nbl_denv = 0;
    while (env[en->nbl_denv])
        en->nbl_denv++;
    en->env = malloc(sizeof(char *) * en->nbl_denv);
    for (int ligne = 0; env[ligne]; ligne++) {
        en->env[ligne] = malloc(sizeof(char) * (my_strlen(env[ligne]) + 1));
        delete_mysh(env, ligne, en);
    }
    en->env[en->nbl_denv] = NULL;
    return en->env;
}
