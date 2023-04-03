/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-1-minishell2-suleman.maqsood
** File description:
** count_letter
*/

int count_letter(char *str, int i)
{
    int nbl = 0;
    while (str[i] != ' ' && str[i] != '\0') {
        nbl++;
        i++;
    }
    nbl++;
    return nbl;
}
