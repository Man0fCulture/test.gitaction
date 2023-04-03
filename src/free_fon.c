/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-1-minishell2-suleman.maqsood
** File description:
** free fon
*/

#include <stdlib.h>
#include "my.h"

void free_fon(env_t *en)
{
    for (int l = 0; en->fon[l]; l++)
        free(en->fon[l]);
    free(en->fon);
}
