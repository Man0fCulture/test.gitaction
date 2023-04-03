/*
** EPITECH PROJECT, 2023
** coding
** File description:
** for_op
*/

#include "my.h"

int check_fonction_op(char **env, env_t *en)
{
    if (check_fonction(env, en) == 0)
        return 1;
    if (en->one == 1) {
        en->one = 0;
        return 1;
    }
    if (exit_fon(env, en) == 0)
        return 1;
    return 0;
}
