/*
** EPITECH PROJECT, 2023
** B-CPE-110-PAR-1-1-BSQ-suleman.maqsood
** File description:
** mapnumber
*/

#include <stdlib.h>
#include "../include/my.h"

void if_dot(map_t *my_map, int_t *to)
{
    if (my_map->bsq[to->l][to->c] == '.') {
        my_map->bsq_int[to->l][to->c] = 1;
        to->check_x = 2;
    }
    if (my_map->bsq[to->l][to->c] == 'o') {
        my_map->bsq_int[to->l][to->c] = 0;
    }
    if (my_map->bsq[to->l][to->c] == '\n') {
        my_map->bsq_int[to->l][to->c] = '\n';
    }
}

int **transf(map_t *my_map, int_t *to)
{
    my_map->bsq_int = malloc(sizeof(int *) * my_map->nbl);
    for (to->l = 0; to->l < my_map->nbl; to->l++) {
        my_map->bsq_int[to->l] = malloc(sizeof(int) * my_map->nbc);
        for (to->c = 0; to->c < my_map->nbc; to->c++) {
            if_dot(my_map, to);
        }
    }
    return my_map->bsq_int;
}
