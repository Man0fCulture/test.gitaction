/*
** EPITECH PROJECT, 2023
** B-CPE-110-PAR-1-1-BSQ-suleman.maqsood
** File description:
** find_square
*/

#include <stdlib.h>
#include "../include/my.h"

int minus(int top_left, int left, int min)
{
    if (min > top_left) {
        min = top_left;
    }
    if (min > left) {
        min = left;
    }
    return min;
}

int save_bigest(int **a, int l, int c, int_t *to)
{
    int top = a[l - 1][c];
    int top_left = a[l - 1][c - 1];
    int left = a[l][c - 1];
    int min = top;
    if (top == 0 || top_left == 0 || left == 0) {
        return a[l][c];
    }
    min = minus(top_left, left, min);
    a[l][c] = a[l][c] + min;
    to->check = 2;
    if (to->bigest < a[l][c]) {
        to->bigest = a[l][c];
        to->l = l;
        to->c = c;
    }
    return a[l][c];
}

int create_bigest(map_t *my_map, int_t *to, int l, int c)
{
    if (my_map->bsq_int[l][c] == '\n') {
        return 0;
    }
    if (l == 0 || c == 0) {
        return 0;
    }
    if (my_map->bsq_int[l][c] != 0)
        my_map->bsq_int[l][c] = save_bigest(my_map->bsq_int, l, c, to);
        else {
        return 0;
        }
    return my_map->bsq_int[l][c];
}

int **square(char *map, map_t *my_map)
{
    int_t *to = malloc(sizeof(to));
    to->check = 1;
    to->check_x = 1;
    if (my_map->i == 0)
        my_map->nbc = count_nbc_max(map);
    transf(my_map, to);
    to->bigest = 0;
    for (int l = 0; l < my_map->nbl; l++) {
        for (int c = 0; c < my_map->nbc; c++) {
            create_bigest(my_map, to, l, c);
        }
    }
    create_square(my_map, to);
    return 0;
}
