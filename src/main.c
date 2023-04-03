/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-1-minishell2-suleman.maqsood
** File description:
** main
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

static char *save_line(char **env, env_t *en)
{
    char *line = NULL;
    en->one = 0;
    en->bin = stock_mypath(env, en);
    en->status = 0;
    stock_env(env, en);
    if (isatty(STDIN_FILENO))
        write(1, "$> ", 3);
    return line;
}

int free_everyting(char *line, env_t *en)
{
    free(line);
    free(en);
    return 0;
}

int main(int argc, char **argv, char **env)
{
    env_t *en = malloc(sizeof(env_t));
    int status = 0;
    char *line = save_line(env, en);
    minishell(line, env, en);
    status = en->status;
    free(en);
    return status;
}
