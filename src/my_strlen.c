/*
** EPITECH PROJECT, 2022
** my_putstr
** File description:
** Displays, one-by-one, the characters of a string.
*/

int my_strlen(char *str)
{
    int i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}
