/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-1-minishell2-suleman.maqsood
** File description:
** str to word operater
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"

static int count_words(char **str, int l)
{
    int nbw = 0;
    while (str[l]) {
        if (str[l][0] == '|' || str[l][0] == '>' || str[l][0] == '<' ||
        str[l][0] == ';' || str[l][0] == '\0')
            break;
        nbw++;
        l++;
    }
    nbw++;
    return nbw;

}

static int save_fon_linked(char **str, int i, int l, fon_t *tmp)
{
    int c = 0;
    tmp->fon[i] = malloc(sizeof(char) * my_strlen(str[l]) + 1);
    while (str[l][c] != '\0') {
        tmp->fon[i][c] = str[l][c];
        c++;
    }
    tmp->fon[i][c] = 0;
    return 0;
}

static int check_if_op(int l, char **str, int i, fon_t *fon)
{
    fon_t *tmp = fon;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    add_pile(fon);
    tmp = tmp->next;
    tmp->fon = malloc(sizeof(char *) * 1);
    tmp->fon[0] = str[l];
    l++;
    if (str[l] == NULL)
        return 1;
    return 0;
}

static int check_operaters(char **str, int *l, int *i, fon_t *fon)
{
    fon_t *tmp = fon;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    if (str[*l][0] == '|' || str[*l][0] == '>' || str[*l][0] == '<' ||
    str[*l][0] == ';') {
        if (check_if_op(*l, str, *i, fon) == 1) {
            *l += 1;
            return 1;
        }
        tmp = tmp->next;
        *l += 1;
        add_pile(fon);
        tmp = tmp->next;
        *i = 0;
        tmp->fon = malloc(sizeof(char *) * count_words(str, *l) + 1);
    }
    save_fon_linked(str, *i, *l, tmp);
    return 0;
}

char **my_array_to_word_operater(char **str, fon_t *fon)
{
    int l = 0;
    int i = 0;
    fon->fon = malloc(sizeof(char *) * count_words(str, l) + 1);
    for (; str[l]; l++) {
        if (check_operaters(str, &l, &i, fon) == 1)
            break;
        i++;
    }
    return fon->fon;
}
