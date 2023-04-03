/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-1-minishell2-suleman.maqsood
** File description:
** write
*/

#include <unistd.h>

void write_stdlineno(void)
{
    if (isatty(STDIN_FILENO))
        write(1, "$> ", 3);
}
