/*
** EPITECH PROJECT, 2022
** my_getnbr
** File description:
** Returns a number, sent to the function as a string
*/

#include <stdio.h>

int neg_or_not(int i, char const *str)
{
    if (i != 0 && str[i - 1] == '-') {
        return -1;
    }
    return 1;
}

int veryfie(const char *str)
{
    int i = 0;
    while ((str[i] < '0' && str[i] > '9') && str[i] != '\0') {
        i++;
    }
    return i;
}

int my_getnbr(const char *str)
{
    int res = 0;
    int i = veryfie(str);
    for (int j = i; str[j] <= '9' && str[j] >= '0' && str[i] != '\0'; j++) {
        res = res * 10 + (str[j] - '0');
    }
    return res * neg_or_not(i, str);
}
