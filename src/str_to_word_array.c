/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-1-minishell1-suleman.maqsood
** File description:
** str to word array
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"

static int count_word(char *str)
{
    int nbw = 0;
    int i = 0;
    while (str[i] == ' ')
        i++;
    for (i; str[i] != '\0'; i++) {
        if (str[i] == ' ') {
            continue;
        }
        if ((str[i] != ' ' && str[i + 1] == ' ') ||
        (str[i] != ' ' && str[i + 1] == '\t') ||
        (str[i] != ' ' && str[i + 1] == '\0') ||
        (str[i] != '\t' && str[i + 1] == ' ') ||
        (str[i] != '\t' && str[i + 1] == '\t') ||
        (str[i] != '\t' && str[i + 1] == '\0'))
            nbw++;
    }
    nbw++;
    return nbw;
}

static int count_letter(char *str, int i)
{
    int nbl = 0;
    while (str[i] != ' ' && str[i] != '\0') {
        nbl++;
        i++;
    }
    nbl++;
    return nbl;
}

static int skip_spacefp(char *str, int i)
{
    i = 0;
    if (str[i] != ' ' && str[i] != '\t')
        return i;
        else {
            while (str[i] == ' ' || str[i] == '\t')
            i++;
        }
    return i;
}

static int skip_space2(char *str, int i)
{
    while (str[i] == ' ' || str[i] == '\t')
        i++;
    return i;
}

char **my_str_to_word_array(char *str)
{
    int nbc;
    int c = 0;
    int nbw = count_word(str);
    int i = 0;
    char **a = malloc(sizeof(char *) * nbw);
    i = skip_spacefp(str, i);
    for (int l = 0; str[i] != '\0'; l++) {
        nbc = count_letter(str, i);
        a[l] = malloc(sizeof(char) * nbc);
        while (str[i] != ' ' && str[i] != '\0' && str[i] != '\t') {
            a[l][c] = str[i];
            i++;
            c++;
        }
        i = skip_space2(str, i);
        a[l][c] = 0;
        c = 0;
    }
    return a;
}
