/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-1-minishell1-suleman.maqsood
** File description:
** main.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "my.h"

int free_everyting(char *line, env_t *en)
{
    free(line);
    free(en);
    return 0;
}

static char *save_line(char **env, env_t *en)
{
    char *line = NULL;
    en->bin = stock_mypath(env, en);
    stock_env(env, en);
    write(1, "$> ", 3);
    return line;
}

static int not_right(env_t *en)
{
    if (en->error == ERROR) {
        free_fon(en);
        en->error = 0;
        return ERROR;
    }
    return 0;
}

int main(int argc, char **argv, char **env)
{
    ssize_t nread;
    env_t *en = malloc(sizeof(env_t));
    size_t len = 0;
    char *line = save_line(env, en);
    while ((nread = getline(&line, &len, stdin)) > 0) {
        line[my_strlen(line) - 1] = '\0';
        if (check_fonction(line, env, en) == 1) {
            continue;
        }
        if (en->fon[0][0] == 'e' && en->fon[0][1] == 'x' && en->fon[0][2]
        == 'i' && en->fon[0][3] == 't' && en->fon[0][4] == '\0')
            return 0;
        if (not_right(en) == ERROR)
            continue;
        if (line[0] != 0)
            my_execute(env, line, en);
        write(1, "$> ", 3);
    }
    free_everyting(line, en);
    return 0;
}
