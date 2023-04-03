/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-1-minishell2-suleman.maqsood
** File description:
** my_special_strlen
*/

static int help_special_strlen(char *str, int i, int nbl)
{
    if (str[i + 1] != 0) {
        if (str[i + 1] == '<' || str[i + 1] == '>') {
            nbl += 2;
            return nbl;
        }
    }
    nbl += 1;
    return nbl;
}

int my_special_strlen(char *str, int i)
{
    int nbl = 0;
    while ((str[i] != ' ') && (str[i] != '\0')) {
        if (str[i] == ';' || str[i] == '|' || str[i] == '>' || str[i] == '<') {
            nbl = help_special_strlen(str, i, nbl);
            return nbl;
        }
        nbl++;
        i++;
    }
    return nbl;
}
