/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** check.c
*/

#include "my.h"
#include "matchstick.h"

int count_stick_line(char *map)
{
    int i = 1;
    int count = 0;

    while (map[i] != '\0') {
        if (map[i] == '|')
            count = count + 1;
        i = i + 1;
    }
    return (count);
}

void print_map(char **map)
{
    for (int i = 0; map[i] != NULL; i++)
        my_printf("%s\n", map[i]);
}

int check_buffer(char *buffer)
{
    int i = 0;
    int count = 0;

    while (buffer[i] != '\0') {
        if ((buffer[i] > 57 || buffer[i] < 48)
        && buffer[i] != '\n' && buffer[i] != '-')
            count = count + 1;
        i = i + 1;
    }
    return (count);
}

int check_bis(game_t *game, map_t *map, char **tab)
{
    if (count_stick_line(tab[game->line]) == 0) {
        my_printf("Error: not enough matches on this line\n");
        game->inc = 0;
        return (0);
    }
    if (game->match > game->stick) {
        my_printf("Error: not enough matches on this line\n");
        game->inc = 0;
        return (0);
    }
    if (game->match > map->max_stick) {
        my_printf("Error: you cannot remove more than");
        my_printf(" %d matches per turn\n", map->max_stick);
        game->inc = 0;
        return (0);
    }
}

int check_victory(char **tab)
{
    int i = 0;
    int idx = 0;
    int count = 0;

    while (tab[i] != NULL) {
        while (tab[i][idx] != '\0') {
            if (tab[i][idx] == '|')
                count = count + 1;
            idx = idx + 1;
        }
        idx = 0;
        i = i + 1;
    }
    return (count);
}