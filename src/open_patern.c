/*
** EPITECH PROJECT, 2023
** B-CPE-110-PAR-1-1-BSQ-suleman.maqsood
** File description:
** open paterne
*/

#include "../include/my.h"
#include <stdlib.h>

int str_len(char *str)
{
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}

int create_paterne(int l, char* patern, map_t *pat, int in)
{
    int c = 0;
    while (c < (pat->nbl)) {
        if (in == pat->i)
            in = 0;
        pat->bsq[l][c] = patern[in];
        in++;
        c++;
    }
    pat->bsq[l][c] = '\n';
    return in;
}

int str_to_word_paterne(char *patern, map_t *pat)
{
    int c = 0;
    int in = 0;
    pat->bsq = malloc(sizeof(char *) * pat->nbl);
    pat->i = str_len(patern);
    pat->nbc = (pat->nbl + 1);
    for (int l = 0; l < pat->nbl; l++) {
        pat->bsq[l] = malloc(sizeof(char) * (pat->nbc));
        in = create_paterne(l, patern, pat, in);
    }
    square(patern, pat);
    return 0;
}

int open_patern(char *nbr, char *paterne)
{
    map_t *pat = malloc(sizeof(map_t));
    if (paterne[0] == '\0')
        return -1;
    for (int i = 0; nbr[i] != '\0'; i++)
        if (nbr[i] < '0' || nbr[i] > '9')
            return -1;
    for (int i = 0; paterne[i] != '\0'; i++)
        if (paterne[i] != '.' && paterne[i] != 'o')
            return -1;
    pat->nbl = my_getnbr(nbr);
    str_to_word_paterne(paterne, pat);
    return 0;
}
