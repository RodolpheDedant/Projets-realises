/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** game.c
*/

#include "my.h"
#include "matchstick.h"

int change_map(game_t *game, char **tab, map_t *map)
{
    int i = 0;
    int count = 0;

    while (tab[game->line][i] != '\0')
        i = i + 1;
    while (tab[game->line][i] != '|')
        i = i - 1;
    while (count < game->match && tab[game->line][i] != '*') {
        if (tab[game->line][i] == '|') {
            tab[game->line][i] = ' ';
            count = count + 1;
        }
        i = i - 1;
    }
    print_map(tab);
    return (0);
}

int matchs(char **tab, map_t *map, game_t *game)
{
    my_printf("Matches: ");
    if (getmatch(tab, map, game) == 1)
        game->inc = 5;
}

int game(char **tab, map_t *map)
{
    game_t *game = malloc(sizeof(game_t));
    game->inc = 0;

    print_map(tab);
    my_printf("\nYour turn:\n");
    while (game->inc < 3) {
        if (game->inc == 0)
            line(tab, map, game);
        if (game->inc == 1) {
            matchs(tab, map, game);
        }
        if (game->inc == 2) {
            ia(tab, map, game);
        }
    }
    free(game);
    return (0);
}