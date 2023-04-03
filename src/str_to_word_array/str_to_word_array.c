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

static char *check_operator2(char **a, char *str, int *i, int l)
{
    int nbc = count_letter(str, *i);
    int c = 0;
    a[l] = malloc(sizeof(char) * nbc);
    while (str[*i] != ' ' && str[*i] != '\0' && str[*i] != '\t') {
        if (str[*i] == ';' || str[*i] == '|' || str[*i] == '>' ||
        str[*i] == '<') {
            a[l][c] = 0;
            return a[l];
        }
        a[l][c] = str[*i];
        *i += 1;
        c++;
    }
    *i = skip_space2(str, *i);
    a[l][c] = 0;
    c = 0;
    return a[l];
}

static char *create_operater(char **a, char *str, int *i, int l)
{
    int c = 0;
    int nbc = my_special_strlen(str, *i);
    a[l] = malloc(sizeof(char) * nbc);
    while (str[*i] == ';' || str[*i] == '|' || str[*i] == '>' ||
    str[*i] == '<') {
        a[l][c] = str[*i];
        *i += 1;
        *i = skip_space2(str, *i);
        c++;
    }
    a[l][c] = 0;
    return a[l];
}

char **my_str_to_word_array(char *str)
{
    int nbw = count_word(str);
    int i = 0;
    char **a = malloc(sizeof(char *) * nbw);
    i = skip_spacefp(str, i);
    for (int l = 0; str[i] != '\0'; l++) {
        a[l] = check_operator2(a, str, &i, l);
        if (str[i] == ';' || str[i] == '|' || str[i] == '>' || str[i] == '<') {
            l++;
            a[l] = create_operater(a, str, &i, l);
        }
    }
    return a;
}
