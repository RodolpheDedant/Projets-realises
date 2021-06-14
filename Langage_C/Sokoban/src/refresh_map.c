/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** refresh_map.c
*/

#include "sokoban.h"

int replace(char **map, char **map_bis, pos_t *pos)
{
    int i = 0;
    int j = 0;

    while (map[j] != NULL && map_bis[j] != NULL) {
        while (map[j][i] != '\0' && map_bis[j][i] != '\0') {
            map[j][i] = map_bis[j][i];
            i = i + 1;
        }
        i = 0;
        j = j + 1;
    }
    pos_player(map, pos);
}