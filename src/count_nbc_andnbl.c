/*
** EPITECH PROJECT, 2023
** B-CPE-110-PAR-1-1-BSQ-suleman.maqsood
** File description:
** nbc or nbl
*/

#include "../include/my.h"
#include <stdlib.h>

int count_nbl(char *map, map_t *maped)
{
    int i = 0;
    char *nbl = malloc(sizeof(char) * (maped->skip));
    while (i != maped->skip) {
        if (nbl[i] < '0' && nbl[i] > '9')
            return -1;
        nbl[i] = map[i];
        i++;
    }
    nbl[maped->skip] = 0;
    maped->nbl = my_getnbr(nbl);
    free(nbl);
    return maped->nbl;
}

int count_nbc(char *map, int i,map_t *maped)
{
    maped->nbc = 0;
    while (map[i] != '\n') {
        maped->nbc++;
        i++;
    }
    maped->nbc += 1;
    return maped->nbc;
}

int compare(int nbc, int max)
{
    if (nbc < max)
        return max;
    if (nbc > max)
        return nbc;
    return max;
}

int count_nbc_max(char *map)
{
    int nbc = 0;
    int max = 0;
    int i = 0;
    while (map[i] != '\0') {
        if (map[i] == '\n') {
            max = compare(nbc, max);
            nbc = 0;
        }
        nbc++;
        i++;
    }
    return max;
}
