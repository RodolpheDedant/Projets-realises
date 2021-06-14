/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** map.c
*/

#include "matchstick.h"

int count_max_line(int x)
{
    int i = 1;
    int count = 1;

    while (i < x) {
        count = count + 2;
        i = i + 1;
    }
    return (count);
}

char **print_game_board(char **tab, map_t *map)
{
    int i = 1;
    int j = 1;

    map->col = map->col - 1;
    while (i < map->line + 1) {
        while (j - 1 < map->col) {
            if (j - 1 <= (map->line + 1) - 2 - i || j >= map->line + i) {
                tab[i][j] = ' ';
            } else
                tab[i][j] = '|';
            j = j + 1;
        }
        tab[i][0] = '*';
        tab[i][j - 1] = '*';
        tab[i][j] = '\0';
        j = 0;
        i = i + 1;
    }
    return (tab);
}

char **print_fence(char **tab, map_t *map)
{
    int i = 0;

    while (i <= map->col) {
        tab[0][i] = '*';
        i = i + 1;
    }
    tab[0][i] = '\0';
    for (int inc = 0; inc <= map->col; inc++)
        tab[map->line + 1][inc] = '*';
    tab[map->line + 1][i] = '\0';
    tab[map->line + 2] = NULL;
    return (tab);
}

char **tab_create(map_t *map)
{
    char **tab = malloc(sizeof(char *) * (map->line + 3));
    int i = 0;
    int y = 0;

    while (i < map->line + 3) {
        tab[i] = malloc(sizeof(char) * (map->col + 2));
        i = i + 1;
    }
    tab = print_game_board(tab, map);
    tab = print_fence(tab, map);
    return (tab);
}