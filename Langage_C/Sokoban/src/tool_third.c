/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** tool_third.c
*/

#include"my.h"
#include "sokoban.h"

int stat_map(char *map)
{
    struct stat info;
    int size_map = 0;

    stat(map, &info);
    if (stat == NULL)
        return (84);
    size_map = info.st_size;
    return (size_map);
}

struct pos *pos_player(char **tab, pos_t *pos)
{
    pos->pos_py = 0;
    pos->pos_px = 0;

    while (tab[pos->pos_py] != NULL) {
        while (tab[pos->pos_py][pos->pos_px] != '\0') {
            if (tab[pos->pos_py][pos->pos_px] == 'P')
                return (pos);
            pos->pos_px = pos->pos_px + 1;
        }
        pos->pos_px = 0;
        pos->pos_py = pos->pos_py + 1;
    }
}

int my_maxline(char **map)
{
    int i = 0;
    int max = 0;

    while (map[i] != NULL) {
        if (max < my_strlen(map[i]))
            max = my_strlen(map[i]);
        i = i + 1;
    }
    return (max);
}

void middle_win(char **map, pos_t *pos)
{
    int x;
    int y;
    int i = 0;

    getmaxyx(stdscr, y, x);
    while (map[i] != NULL) {
        mvprintw((y - pos->row)/2 + i, (x - my_maxline(map))/2, "%s", map[i]);
        i = i + 1;
    }
}

void check_size(pos_t *pos)
{
    int x;
    int y;

    getmaxyx(stdscr, y, x);
    if (x < pos->col || y < pos->row) {
        my_printf("TERMINAL IS TOO SMALL");
        exit(84);
    }
}