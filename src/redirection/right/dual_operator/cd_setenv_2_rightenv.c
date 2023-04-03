/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-1-minishell2-suleman.maqsood
** File description:
** special right
*/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int check_cd_right_right(char **env, env_t *en, fon_t *tmp)
{
    if (en->fon[0][0] == 'c' && en->fon[0][1] == 'd') {
        already_exist_void_file(tmp->next->next->fon[0]);
        if (en->fon[1] == NULL || en->fon[1][0] == '~') {
            cd_to_home(en);
            return 0;
        }
        if (en->fon[1][0] == '-' && en->old_pwd != NULL) {
            cd_minus(en);
            return 0;
        }
        create_cd(en->fon[1], env, en);
        return 0;
    }
    return 1;
}

int special_for_double_right_print_env(env_t *en, char *name)
{
    int fd = open(name, O_WRONLY | O_APPEND | O_CREAT, 00666);
    if (fd == -1) {
        perror("open");
        exit(1);
    }
    if (en->env == NULL) {
        write(1, "\n", 1);
        close(fd);
        return 0;
    }
    for (int i = 0; en->env[i]; i++) {
        write(fd, en->env[i], my_strlen(en->env[i]));
        write(fd, "\n", 1);
    }
    close(fd);
    return 0;
}

int special_for_double_right_env_check(env_t *en, char *name)
{
    if (en->fon[0][0] == 'e' && en->fon[0][1] == 'n' && en->fon[0][2] == 'v') {
        if (en->fon[1] != NULL) {
            write(1, "env: Too many arguments.\n", 26);
            return 0;
        }
        special_for_double_right_print_env(en, name);
    }
    return 1;
}

int special_double_right_help_check_setenv(char **env, env_t *en, char *name)
{
    if (en->fon[1] == NULL) {
        special_for_double_right_print_env(en, name);
        return 0;
    }
    already_exist_void_file(name);
    if ((en->fon[1][0] < 'a' || en->fon[1][0] > 'z') &&
    (en->fon[1][0] < 'A' || en->fon[1][0] > 'Z') &&
        en->fon[1][0] != '_') {
        write(1, "setenv: Variable name must begin with a letter.\n", 49);
        en->one = 1;
        return 0;
    }
    if (second_time(en) == 0) {
        return 0;
    }
    set_env(en);
    return 0;
}
