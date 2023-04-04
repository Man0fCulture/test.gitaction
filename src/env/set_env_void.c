/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-1-minishell1-suleman.maqsood
** File description:
** setenv is void
*/

#include <stdlib.h>
#include <my.h>

static int my_strlen_for_setenv(char *fon)
{
    int i = 0;
    while (fon[i] != '\0') {
        if (fon[i] == '=') {
            break;
        }
        i++;
    }
    return i;
}

static int itexist(int l, int size, env_t *en)
{
    int c = 0;
    if (en->env[l][c] == en->fon[1][c]) {
        while (en->env[l][c] == en->fon[1][c]) {
            c++;
        }
        if (size == c)
            return 1;
    }
    return 0;
}

static int check_if_it_exist(int *check, env_t *en)
{
    int l = 0;
    int size;
    while (en->env[l] != NULL) {
        size = my_strlen_for_setenv(en->env[l]);
        if (itexist(l, size, en) == 1) {
            check[0] = 1;
            break;
        }
        l++;
    }
    return l;
}

static void realoc_the_line(int l, env_t *en)
{
    int c = 0;
    int i = 0;
    int nbc = my_strlen(en->fon[1]);
    nbc += 1;
    free(en->env[l]);
    en->env[l] = malloc(sizeof(char) * nbc);
    while (en->fon[1][c] != 0) {
        en->env[l][c] = en->fon[1][c];
        c++;
    }
    en->env[l][c] = '=';
    c++;
    en->env[l][c] = 0;
}

int set_env_void(env_t *en)
{
    int l;
    int check = 0;
    l = check_if_it_exist(&check, en);
    if (check == 1) {
        realoc_the_line(l, en);
    } else {
        create_new_env_void(en);
    }
    return 0;
}
