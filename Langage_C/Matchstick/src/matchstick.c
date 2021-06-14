/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** matchstick.c
*/

#include "my.h"
#include "matchstick.h"

void del_tab(char **str)
{
    int i = 0;

    while (str[i] != NULL) {
        free(str[i]);
        i = i + 1;
    }
    free(str);
}

int error(map_t *map)
{
    if (!(map->line > 1 && map->line < 100)) {
        my_printf("Too much line or not enough line, line : 1 < nb < 100");
        return (84);
    }
    if (!(map->max_stick > 0)) {
        my_printf("not enough match stick: nb > 0");
        return (84);
    }
}

int matchstick(char **av)
{
    map_t *map = malloc(sizeof(map_t));
    map->line = my_getnbr(av[1]);
    map->col = count_max_line(my_getnbr(av[1])) + 2;
    map->max_stick = my_getnbr(av[2]);
    map->ret_val = 0;
    int ret = 0;
    char **tab = tab_create(map);

    if (error(map) == 84) {
        del_tab(tab);
        return (84);
    }
    game(tab, map);
    del_tab(tab);
    ret = map->ret_val;
    free(map);
    return (ret);
}