/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** all_move.c
*/

#include "sokoban.h"

int up(pos_t *pos, char **map, char **map_bis)
{
    if (map[pos->pos_py - 2][pos->pos_px] == '#'
        || map[pos->pos_py - 2][pos->pos_px] == 'X')
            return (0);
        if (map_bis[pos->pos_py][pos->pos_px] == 'O') {
            map[pos->pos_py][pos->pos_px] = 'O';
        } else
            map[pos->pos_py][pos->pos_px] = ' ';
        map[pos->pos_py - 2][pos->pos_px] = 'X';
        map[pos->pos_py - 1][pos->pos_px] = 'P';
        pos->pos_py--;
}

int do_up(pos_t *pos, char **map, char **map_bis)
{
    if (map[pos->pos_py - 1][pos->pos_px] == ' '
        || map[pos->pos_py - 1][pos->pos_px] == 'O') {
        if (map_bis[pos->pos_py][pos->pos_px] == 'O') {
            map[pos->pos_py][pos->pos_px] = 'O';
        } else
            map[pos->pos_py][pos->pos_px] = ' ';
        map[pos->pos_py - 1][pos->pos_px] = 'P';
        pos->pos_py--;
        return (0);
    }
    if (map[pos->pos_py - 1][pos->pos_px] == 'X') {
        up(pos, map, map_bis);
        return (0);
    }
}