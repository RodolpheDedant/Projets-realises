/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** line.c
*/

#include "matchstick.h"
#include "my.h"

int check_line(char *buffer, map_t *map, char **tab, game_t *game)
{
    if (buffer[0] == '\n')
        return (0);
    if (buffer[0] == '-' && (buffer[1] > 57 || buffer[1] < 48)) {
        my_printf("Error: invalid input (positive number expected)\n");
        return (0);
    }
    if (check_buffer(buffer) > 0) {
        my_printf("Error: invalid input (positive number expected)\n");
        return (0);
    }
    game->line = my_getnbr(buffer);
    if (game->line > map->line || game->line < 1) {
        my_printf("Error: this line is out of range\n");
        return (0);
    }
    return (1);
}

int my_getline(char **tab, map_t *map, game_t *game)
{
    ssize_t size;
    char *buffer = NULL;
    int return_value = getline(&buffer, &size, stdin);

    if (buffer == NULL)
        return (0);
    if (return_value <= 0) {
        return (1);
    }
    if (check_line(buffer, map, tab, game) == 1)
        game->inc = 1;
    return (0);
}

int line(char **tab, map_t *map, game_t *game)
{
    my_printf("Line: ");
    if (my_getline(tab, map, game) == 1)
        game->inc = 5;
    return (0);
}