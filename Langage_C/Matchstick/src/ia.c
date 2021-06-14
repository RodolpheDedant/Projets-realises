/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** ia.c
*/

#include "matchstick.h"
#include "my.h"

void game_ia(game_t *game, char **tab, map_t *map)
{
    my_printf("\nAI's turn...\n");
    my_printf("AI removed %d match(es) ", game->match);
    my_printf("from line %d\n", game->line);
    change_map(game, tab, map);
    game->inc = 0;
}

int victory(map_t *map, game_t *game)
{
    map->ret_val = 1;
    my_printf("I lost... snif... but I'll get you next time!!\n");
    game->inc = 5;
}

int ia(char **tab, map_t *map, game_t *game)
{
    if (check_victory(tab) == 0) {
        map->ret_val = 2;
        my_printf("You lost, too bad...\n");
        game->inc = 5;
        return (0);
    }
    game->line = random() % (map->line + 1);
    game->match = random() % (map->max_stick + 1);
    if ((game->line <= map->line && game->line > 0
    && count_stick_line(tab[game->line]) > 0)
    && ((game->match <= map->max_stick
    && game->match <= count_stick_line(tab[game->line])) && game->match > 0)) {
        game_ia(game, tab, map);
        if (check_victory(tab) == 0) {
            victory(map, game);
            return (0);
        }
        my_printf("\nYour turn:\n");
    }
    return (0);
}