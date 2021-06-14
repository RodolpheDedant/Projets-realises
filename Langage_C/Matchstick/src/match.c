/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** match.c
*/

#include "my.h"
#include "matchstick.h"

int check_match(char *buffer, map_t *map, char **tab, game_t *game)
{
    if (check_buffer(buffer) > 0) {
        my_printf("Error: invalid input (positive number expected)\n");
        game->inc = 0;
        return (0);
    }
    game->match = my_getnbr(buffer);
    game->stick = count_stick_line(tab[game->line]);
    if (game->match < 1) {
        my_printf("Error: you have to remove at least one match\n");
        game->inc = 0;
        return (0);
    }
    if (check_bis(game, map, tab) == 0)
        return (0);
    my_printf("Player removed %d match(es) ", game->match);
    my_printf("from line %d\n", game->line);
    change_map(game, tab, map);
    return (1);
}

int getmatch(char **tab, map_t *map, game_t *game)
{
    ssize_t size;
    char *buffer = NULL;
    int return_value = getline(&buffer, &size, stdin);

    if (buffer == NULL || buffer[0] == '\n')
        return (0);
    if (buffer[0] == '-' && (buffer[1] > 57 || buffer[1] < 48)) {
        my_printf("Error: invalid input (positive number expected)\n");
        return (0);
    }
    if (return_value <= 0)
        return (1);
    if (check_match(buffer, map, tab, game) == 1)
        game->inc = 2;
    return (0);
}