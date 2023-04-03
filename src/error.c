/*
** EPITECH PROJECT, 2023
** B-CPE-110-PAR-1-1-BSQ-suleman.maqsood
** File description:
** error
*/

#include "../include/my.h"

int error(int ac, char **argv)
{
    if (ac == 1)
        return -1;
    if (ac > 3)
        return -1;
    return 0;
}
