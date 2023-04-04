/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-1-minishell1-suleman.maqsood
** File description:
** minishell
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include "my.h"

void free_fon(env_t *en)
{
    for (int l = 0; en->fon[l]; l++)
        free(en->fon[l]);
    free(en->fon);
}

static char *concate(char *fon, char *bin)
{
    char *arg;
    int index = 0;
    int i = my_strlen(fon);
    i += my_strlen(bin);
    arg = malloc(sizeof(char) * i);
    for (int in = 0; bin[in] != '\0'; in++) {
        arg[index] = bin[in];
        index++;
    }
    arg[index] = '/';
    index++;
    for (int in = 0; fon[in] != '\0'; in++) {
        arg[index] = fon[in];
        index++;
    }
    arg[i + 1] = 0;
    return arg;
}

static int check_if_it_exist(int l, char **env, env_t *en)
{
    char *arg;
    int check = 0;
    while (l < en->nbw) {
        arg = concate(en->fon[0], en->bin[l]);
        if (execve(arg, en->fon, env) == -1)
            check++;
        l++;
    }
    if (check == en->nbw) {
        my_putstr(en->fon[0]);
        write(1, ": Command not found.", 21);
        write(1, "\n", 1);
        free_fon(en);
        return 1;
    }
    free_fon(en);
    return 0;
}

int my_execute(char **env, char *line, env_t *en)
{
    pid_t pid = 0;
    int status = 0;
    int l = 0;
    pid = fork();
    if (pid == 0) {
        check_if_it_exist(l, env, en);
        exit(0);
    } else {
        waitpid(pid, &status, 0);
        kill(pid, SIGTERM);
        free_fon(en);
        return 0;
    }
    return 0;
}
