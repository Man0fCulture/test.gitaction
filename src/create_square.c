/*
** EPITECH PROJECT, 2023
** B-CPE-110-PAR-1-1-BSQ-suleman.maqsood
** File description:
** create square
*/

#include "../include/my.h"

static int ifonlyoneline(map_t *my_map, int_t *to)
{
    int c = 0;
    int l = 0;
    if (to->check_x == 1)
        return 0;
    while (my_map->bsq[l][c] != '.') {
        c++;
        if (my_map->bsq[l][c] == my_map->nbc) {
        l++;
        c = 0;
        }
    }
    my_map->bsq[l][c] = 'x';
    return 0;
}

int create_square(map_t *my_map, int_t *to)
{
    int l = 0;
    for (int l = to->l; l > (to->l - to->bigest); l--) {
        for (int c = to->c; c > (to->c - to->bigest); c--) {
            my_map->bsq[l][c] = 'x';
        }
    }
    if (to->check == 1) {
        ifonlyoneline(my_map, to);
    }
    while (l < my_map->nbl) {
        my_putstr(my_map->bsq[l]);
        l++;
    }
    return 0;
}
