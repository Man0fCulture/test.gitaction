/*
** EPITECH PROJECT, 2023
** B-CPE-110-PAR-1-1-BSQ-suleman.maqsood
** File description:
** main
*/

#include <stdlib.h>
#include "../include/my.h"

int main(int ac, char **argv)
{
    map_t *my_map = malloc(sizeof(map_t));
    if (error(ac, argv) == -1) {
        free(my_map);
        return 84;
    }
    if (ac == 3) {
        if (open_patern(argv[1], argv[2]) == -1) {
            free(my_map);
            return 84;
        }
    }
    if (ac == 2) {
        if (open_file(argv[1], my_map) == -1) {
            free(my_map);
            return 84;
        }
    }
    return 0;
}
