/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-1-minishell2-suleman.maqsood
** File description:
** launch op
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

static int check_first(int *step, fon_t *tmp)
{
    if (*step == 0) {
        *step += 1;
        return 0;
    }
    if (tmp->prec->fon[0][0] == '<' || tmp->prec->fon[0][0] == '>')
        return 1;
    return 0;
}

static int boucle_for_operater(char **env, env_t *en, fon_t *tmp)
{
    int step = 0;
    int ok = 1;
    for (;tmp != NULL; tmp = tmp->next) {
        en->fon = tmp->fon;
        if (tmp->fon[0][0] == ';' || tmp->fon[0][0] == '|' ||
        tmp->fon[0][0] == '>' || tmp->fon[0][0] == '<')
            continue;
        if (check_first(&step, tmp) == 1)
            continue;
        if (special_direction(tmp->fon, env, en, tmp) == 1)
            continue;
        if (check_fonction_op(env, en) == 1)
            continue;
        my_execute(env, en);
    }
    return 0;
}

static int operater(char **env, env_t *en, fon_t *fon)
{
    fon_t *tmp = fon->next;
    my_array_to_word_operater(en->fon, tmp);
    boucle_for_operater(env, en, tmp);
    tmp = fon->next;
    free_pile(fon);
    return 0;
}

int operater_is_here(char **env, env_t *en, fon_t *fon)
{
    for (int l = 0; en->fon[l]; l++) {
            if (en->fon[l][0] == ';' || en->fon[l][0] == '|' || en->fon[l][0]
            == '>' || en->fon[l][0] == '<') {
                add_pile(fon);
                operater(env, en, fon);
                return 1;
            }
    }
    return 0;
}
