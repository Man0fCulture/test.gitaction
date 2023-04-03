/*
** EPITECH PROJECT, 2023
** B-CPE-110-PAR-1-1-BSQ-suleman.maqsood
** File description:
** bsq
*/

#include "../include/my.h"
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int skip_first_line(char *map)
{
    int i = 0;
    while (map[i] != '\n')
        i++;
    return (i + 1);
}

static int check_if_doto(char *map, map_t *my_map, int l)
{
    for (int c = 0; (c < my_map->nbc); c++) {
        if (map[my_map->i] != '.' && map[my_map->i] != 'o' &&
        map[my_map->i] != '\n' && map[my_map->i] != '\0') {
            return -1;
        }
            my_map->bsq[l][c] = map[my_map->i];
            my_map->i++;
        }
    return 0;
}

int str_to_word_array(char *map, map_t *my_map)
{
    int l = 0;
    my_map->i = my_map->skip;
    my_map->bsq = malloc(sizeof(char *) * my_map->nbl);
    while (map[my_map->i] != '\0') {
        count_nbc(map, my_map->i, my_map);
        my_map->bsq[l] = malloc(sizeof(char) * my_map->nbc);
        if (check_if_doto(map, my_map, l) == -1)
            return -1;
        l++;
    }
    if (l != my_map->nbl)
        return -1;
    my_map->i = 0;
    square(map, my_map);
    return 0;
}

int open_file(char *map, map_t *my_map)
{
    struct stat sd;
    char *buf;
    int readed;
    int fd = open(map, O_RDONLY);
    if (fd == -1)
        return -1;
    stat(map, &sd);
    buf = malloc(sizeof(char) * (sd.st_size + 1));
    readed = read(fd, buf, sd.st_size);
    if (sd.st_size == 0 || readed == -1 || readed == 0)
        return -1;
    buf[sd.st_size + 1] = 0;
    my_map->skip = skip_first_line(buf);
    if (count_nbl(buf, my_map) == -1)
        return -1;
    if (str_to_word_array(buf, my_map) == -1)
        return -1;
    close(fd);
    return 0;
}
