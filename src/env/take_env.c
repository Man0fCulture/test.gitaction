/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-1-minishell1-suleman.maqsood
** File description:
** take path into env
*/

#include <stdlib.h>
#include "my.h"

static int find_path(char **env)
{
    int l = 0;
    while (env[l]) {
        if (env[l][2] == 'T' && env[l][3] == 'H' && env[l][0] == 'P'
    && env[l][1] == 'A') {
        break;
    }
        l++;
    }
    return l;
}

static int count_nbw(char *env, int *i)
{
    int nbw = 0;
    for (int c = 0; env[c] != '\0'; c++) {
        if (env[c] == '=')
            i[0] = c + 1;
        if (env[c] == ':' || env[c] == 0)
            nbw++;
    }
    nbw++;
    return nbw;
}

static int sizeofpath(char *str, int i)
{
    int size = 0;
    while (str[i] != ':' && str[i] != 0) {
        size++;
        i++;
    }
    return size;
}

char **stock_mypath(char **env, env_t *en)
{
    int i = 0;
    int li = 0;
    int y = 0;
    int l = find_path(env);
    en->nbw = count_nbw(env[l], &i);
    char **path = malloc(sizeof(char *) * en->nbw);
    for (int in = i; env[l][in] != 0; li++) {
        path[li] = malloc(sizeof(char) * (sizeofpath(env[l], in)));
        while (env[l][in] != ':' && env[l][in] != 0) {
            path[li][y] = env[l][in];
            y++;
            in++;
        }
        path[li][y] = 0;
        y = 0;
        if (env[l][in] != 0)
            in++;
    }
    return path;
}
