/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-1-minishell2-suleman.maqsood
** File description:
** create void
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int create_void_file(char *name)
{
    int fd = open(name, O_WRONLY | O_TRUNC | O_CREAT, 00666);
    if (fd == -1) {
        perror("open");
        exit(1);
    }
    close(fd);
    return 0;
}
