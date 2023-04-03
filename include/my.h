/*
** EPITECH PROJECT, 2023
** B-CPE-110-PAR-1-1-BSQ-suleman.maqsood
** File description:
** my.h
*/

#ifndef MY_H_
    #define MY_H_

typedef struct map_s {
    char **bsq;
    int skip;
    int nbl;
    int nbc;
    int **bsq_int;
    int i;
}map_t;

typedef struct int_s {
    int l;
    int c;
    int bigest;
    int check;
    int check_x;
}int_t;

int count_nbl(char *map, map_t *maped);
int count_nbc(char *map, int i,map_t *maped);
int my_getnbr(const char *str);
void my_putchar(char c);
int my_putstr(char const *str);
int count_nbc_max(char *map);
int **transf(map_t *my_map, int_t *to);
int **square(char *map, map_t *my_map);
int create_square(map_t *my_map, int_t *to);
int open_patern(char *nbr, char *paterne);
int error(int ac, char **argv);
int open_file(char *map, map_t *my_map);

#endif
