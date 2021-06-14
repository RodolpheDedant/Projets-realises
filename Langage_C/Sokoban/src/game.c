/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** game.c
*/

#include "sokoban.h"
#include "my.h"

int choice(pos_t *pos, char **map, int move, char **map_bis)
{
        if (move == 27) {
            endwin();
            exit(0);
        }
        if (move == KEY_UP && map[pos->pos_py - 1][pos->pos_px] != '#')
            do_up(pos, map, map_bis);
        if (move == KEY_DOWN && map[pos->pos_py + 1][pos->pos_px] != '#')
            do_down(pos, map, map_bis);
        if (move == KEY_RIGHT && map[pos->pos_py][pos->pos_px + 1] != '#')
            do_right(pos, map, map_bis);
        if (move == KEY_LEFT && map[pos->pos_py][pos->pos_px - 1] != '#')
            do_left(pos, map, map_bis);
        if (move == 32)
            replace(map, map_bis, pos);
}

int veri(char **map, char **map_bis)
{
    int y = 0;
    int x = 0;

    while (map[y] != NULL && map_bis[y] != NULL) {
        while (map[y][x] != '\0' && map_bis[y][x] != '\0') {
            if (map[y][x] == 'X' && map_bis[y][x] != 'O')
                return (0);
            x = x + 1;
        }
        x = 0;
        y = y + 1;
    }
    return (1);
}

int quit(pos_t *pos, char **map, char **map_bis)
{
    clear();
    middle_win(map, pos);
    refresh();
    usleep(200000);
    f_arr(map, pos->row);
    f_arr_bis(map_bis, pos->row);
    free(pos);
    endwin();
    exit(0);
}

int init(char **map, pos_t *pos, char **map_bis)
{
    int move;

    initscr();
    noecho();
    keypad(stdscr, TRUE);
    refresh();
    check_size(pos);
    while (1) {
        clear();
        middle_win(map, pos);
        move = getch();
        if (move == -1)
            exit(84);
        choice(pos, map, move, map_bis);
        refresh();
        if (veri(map, map_bis) == 1)
            quit(pos, map, map_bis);
    }
    endwin();
}

int game(char *buffer)
{
    pos_t *pos = malloc(sizeof(pos_t));
    char **map = cut_str(buffer);
    char **map_save = cut_str_bis(buffer);

    pos->row = count_word(buffer);
    pos->col = count_char(buffer);
    pos_player(map, pos);
    init(map, pos, map_save);
    f_arr_bis(map_save, pos->row);
    f_arr(map, pos->row);
    return (0);
}