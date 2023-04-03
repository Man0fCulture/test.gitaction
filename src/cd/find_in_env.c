/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-1-minishell1-suleman.maqsood
** File description:
** find_in_env
*/

#include "my.h"

int find_old_pwd(char **env)
{
    int l = 0;
    while (env[l]) {
        if (env[l][0] == 'O' && env[l][1] == 'L'
    && env[l][2] == 'D' && env[l][3] == 'P' &&
    env[l][4] == 'W' && env[l][5] == 'D') {
        break;
        }
        l++;
    }
    return l;
}

int find_pwd(char **env)
{
    int l = 0;
    while (env[l]) {
        if (env[l][0] == 'P' && env[l][1] == 'W'
    && env[l][2] == 'D') {
        break;
        }
        l++;
    }
    return l;
}

int find_home(char **env)
{
    int l = 0;
    while (env[l]) {
        if (env[l][0] == 'H' && env[l][1] == 'O'
    && env[l][2] == 'M' && env[l][3] == 'E') {
        break;
        }
        l++;
    }
    return l;
}
