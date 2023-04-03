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

static char *take_the_line(char *line, env_t *en, fon_t *fon)
{
    if (line[my_strlen(line) - 1] == '\n')
        line[my_strlen(line) - 1] = '\0';
    return line;
}

int exit_fon(char **env, env_t *en)
{
    if (en->fon[0][0] == 'e' && en->fon[0][1] == 'x' && en->fon[0][2]
    == 'i' && en->fon[0][3] == 't' && en->fon[0][4] == '\0')
        return 0;
    return 1;
}

static int minishell2(char **env, env_t *en, fon_t *fon)
{
    if (operater_is_here(env, en, fon) == 1)
        return 0;
    if (check_fonction(env, en) == 0)
            return 0;
    if (en->one == 1) {
            en->one = 0;
            return 0;
        }
        if (exit_fon(env, en) == 0)
            return 0;
        my_execute(env, en);
    return 0;
}

static int ignore_all_space_tab(char *line)
{
    int i = 0;
    int check = 0;
    int nbl = my_strlen(line);
    while (line[i] != '\0') {
        if (line[i] == ' ' || line[i] == '\t')
            check++;
        i++;
    }
    if (check == nbl)
        return 0;
    return 1;
}

void minishell(char *line, char **env, env_t *en)
{
    ssize_t nread;
    size_t len = 0;
    fon_t *fon = malloc(sizeof(fon_t));
    while ((nread = getline(&line, &len, stdin)) > 0) {
        line = take_the_line(line, en, fon);
        if (line[0] == 0) {
            write_stdlineno();
            continue;
        }
        if (ignore_all_space_tab(line) == 0) {
            write_stdlineno();
            free_fon(en);
            continue;
        }
        en->fon = my_str_to_word_array(line);
        minishell2(env, en, fon);
        write_stdlineno();
        free_fon(en);
    }
}
