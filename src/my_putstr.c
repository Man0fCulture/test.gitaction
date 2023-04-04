/*
** EPITECH PROJECT, 2022
** my_putstr
** File description:
** Displays, one-by-one, the characters of a string.
*/

#include <unistd.h>

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return write(1, str, i);
}
