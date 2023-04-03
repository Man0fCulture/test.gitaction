/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-1-minishell2-suleman.maqsood
** File description:
** count_words
*/

static int count_word_stock_the_op(char *str, int i, int nbw)
{
    if (str[i + 1] == '<' || str[i + 1] == '>') {
        nbw += 1;
        i += 1;
        return nbw;
    }
    if (str[i - 1] != ' ' && str[i - 1] != '\t')
        nbw += 1;
    if (str[i + 1] != ' ' && str[i + 1] != '\t') {
        nbw += 1;
        } else {
        nbw += 1;
    }
    nbw += 1;
    return nbw;
}

static int help_count_word(char *str, int *i, int *nbw)
{
    if (str[*i] == ';' || str[*i] == '|' ||
        str[*i] == '>' || str[*i] == '<') {
            if (str[*i + 1] != 0) {
                *nbw = count_word_stock_the_op(str, *i, *nbw);
                return 0;
            }
        }
    if ((str[*i] != ' ' && str[*i + 1] == ' ') ||
    (str[*i] != ' ' && str[*i + 1] == '\t') ||
    (str[*i] != ' ' && str[*i + 1] == '\0') ||
    (str[*i] != '\t' && str[*i + 1] == ' ') ||
    (str[*i] != '\t' && str[*i + 1] == '\t') ||
    (str[*i] != '\t' && str[*i + 1] == '\0'))
        *nbw += 1;
    return 0;
}

int count_word(char *str)
{
    int nbw = 0;
    int i = 0;
    while (str[i] == ' ')
        i++;
    for (i; str[i] != '\0'; i++) {
        if (str[i] == ' ') {
            continue;
        }
        help_count_word(str, &i, &nbw);
    }
    nbw += 1;
    return nbw;
}
