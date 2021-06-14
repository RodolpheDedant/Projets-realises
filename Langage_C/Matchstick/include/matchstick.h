/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** matchstick.h
*/

#ifndef MATCHSTICK_H
#define MATCHSTICK_H

#include <stdlib.h>
#include <time.h>

typedef struct map {
    int line;
    int col;
    int max_stick;
    int ret_val;
}map_t;

typedef struct game {
    int line;
    int match;
    int stick;
    int inc;
}game_t;

int matchstick(char **av);
char **tab_create(map_t *map);
char **print_fence(char **tab, map_t *map);
char **print_game_board(char **tab, map_t *map);
int count_max_line(int x);
int game(char **tab, map_t *map);
int line(char **tab, map_t *map, game_t *game);
int change_map(game_t *game, char **tab, map_t *map);
int getmatch(char **tab, map_t *map, game_t *game);
int ia(char **tab, map_t *map, game_t *game);
void print_map(char **map);
int check_buffer(char *buffer);
int check_victory(char **tab);
int check_bis(game_t *game, map_t *map, char **tab);
int count_stick_line(char *map);

#endif