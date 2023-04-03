/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-1-minishell2-suleman.maqsood
** File description:
** special execute right
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <fcntl.h>
#include <signal.h>
#include "my.h"

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

static int check_segfault(int status)
{
    if (WIFSIGNALED(status)) {
        if (WTERMSIG(status) == SIGSEGV) {
            write(1, "Segmentation fault\n", 19);
            return 1;
        }
    }
    return 0;
}

static int if_not_found(char *name, int tmp_fd, env_t *en)
{
    already_exist_void_file(name);
    write(tmp_fd, en->fon[0], my_strlen(en->fon[0]));
    write(tmp_fd, ": Command not found.\n", 22);
    en->status = 1;
    close(tmp_fd);
    free_fon(en);
}

static int check_if_it_exist(int l, char **env, char *name, env_t *en)
{
    char *arg;
    int check = 0;
    int fd = open(name, O_WRONLY | O_APPEND | O_CREAT, 00666);
    int tmp_fd = dup(1);
    dup2(fd, STDOUT_FILENO);
    while (l < en->nbw) {
        arg = concate(en->fon[0], en->bin[l]);
        if (execve(arg, en->fon, env) != -1) {
            close(fd);
            break;
        }
        check++;
        l++;
    }
    if (check == en->nbw) {
        if_not_found(name, tmp_fd, en);
        return 1;
    }
    return 0;
}

int special_for_double_right_my_execute(char **env, env_t *en, fon_t *tmp)
{
    pid_t pid = 0;
    int status = 0;
    int l = 0;
    pid = fork();
    if (pid == 0) {
        check_if_it_exist(l, env, tmp->next->next->fon[0], en);
        exit(1);
    } else {
        waitpid(pid, &status, 0);
        kill(pid, SIGTERM);
        return 0;
    }
    return 0;
}
