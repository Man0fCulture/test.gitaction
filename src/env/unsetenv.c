/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-1-minishell1-suleman.maqsood
** File description:
** unsetenv
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

int un_set_env(env_t *en)
{
    int l;
    int check = 0;
    l = check_if_it_exist(&check, en);
    if (check == 1) {
        delete_ele_env(l, en);
        return 1;
    } else {
        return ERROR;
    }
    return 0;
}
