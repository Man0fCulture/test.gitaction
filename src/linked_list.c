/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-1-minishell2-suleman.maqsood
** File description:
** linked liste
*/

#include <stdlib.h>
#include "my.h"

static fon_t *create_pile(fon_t *node)
{
    fon_t *pile = malloc(sizeof(fon_t));
    pile->next = NULL;
    pile->prec = NULL;
    return pile;
}

fon_t *add_pile(fon_t *node)
{
    fon_t *curr = node;
    fon_t *prec = node;
    fon_t *pile;
    pile = create_pile(node);
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = pile;
    pile->prec = curr;
    pile->next = NULL;
    return node;
}

void *free_pile(fon_t *a)
{
    fon_t *tmp = a;
    fon_t *save;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    while (a->next != NULL) {
        save = tmp->prec;
        save->next = NULL;
        free(tmp);
        tmp = save;
    }
    free(a);
}
