/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** sokoban.h
*/

#ifndef SOKOBAN_H
#define SOKOBAN_H

#include <ncurses.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <sys/stat.h>

typedef struct map {
    int fd;
    int size;
    int ret;
}map_t;

typedef struct pos {
    int pos_px;
    int pos_py;
    int row;
    int col;
}pos_t;

int sokoban(int ac, char **av);
int game(char *buffer);
char **cut_str(char *str);
char **cut_str_bis(char *str);
int count_char(char *str);
int count_word(char *str);
void f_arr(char **arr, int nb_rows);
void f_arr_bis(char **arr, int nb_rows);
int do_left(pos_t *pos, char **map, char **map_bis);
int do_right(pos_t *pos, char **map, char **map_bis);
int do_down(pos_t *pos, char **map, char **map_bis);
int do_up(pos_t *pos, char **map, char **map_bis);
int replace(char **map, char **map_bis, pos_t *pos);
struct pos *pos_player(char **tab, pos_t *pos);
struct pos *pos_player(char **tab, pos_t *pos);
void middle_win(char **map, pos_t *pos);
void check_size(pos_t *pos);
int stat_map(char *map);
void help(void);

#endif