/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** move_left.c
*/

#include "sokoban.h"

int left(pos_t *pos, char **map, char **map_bis)
{
    if (map[pos->pos_py][pos->pos_px - 2] == '#'
        || map[pos->pos_py][pos->pos_px - 2] == 'X')
            return (0);
        if (map_bis[pos->pos_py][pos->pos_px] == 'O') {
            map[pos->pos_py][pos->pos_px] = 'O';
        } else
            map[pos->pos_py][pos->pos_px] = ' ';
        map[pos->pos_py][pos->pos_px - 2] = 'X';
        map[pos->pos_py][pos->pos_px - 1] = 'P';
        pos->pos_px--;
}

int do_left(pos_t *pos, char **map, char **map_bis)
{
    if (map[pos->pos_py][pos->pos_px - 1] == ' '
        || map[pos->pos_py][pos->pos_px - 1] == 'O') {
        if (map_bis[pos->pos_py][pos->pos_px] == 'O') {
            map[pos->pos_py][pos->pos_px] = 'O';
        } else
            map[pos->pos_py][pos->pos_px] = ' ';
        map[pos->pos_py][pos->pos_px - 1] = 'P';
        pos->pos_px--;
        return (0);
    }
    if (map[pos->pos_py][pos->pos_px - 1] == 'X') {
        left(pos, map, map_bis);
        return (0);
    }
}