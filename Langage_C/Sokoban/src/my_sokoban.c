/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** my_sokoban.c
*/

#include "my.h"
#include "sokoban.h"

int error_box_hole(char *buffer)
{
    int i = 0;
    int box = 0;
    int hole = 0;

    while (buffer[i] != '\0') {
        if (buffer[i] == 'X')
            box = box + 1;
        if (buffer[i] == 'O')
            hole = hole + 1;
        i = i + 1;
    }
    if (box != hole)
        return (84);
    return (0);
}

void help(void)
{
    my_printf("USAGE\n");
    my_printf("     ./my_sokoban map\n");
    my_printf("DESCRIPTION\n");
    my_printf("     map file representing warehouse map, containing '#' for");
    my_printf("walls, \n         ");
    my_printf("'P' for the player, 'X' for boxes and 'O' for storages");
    my_printf(" locations.\n");
}

int check(char *map)
{
    int i = 0;
    int count = 0;

    while (map[i] != '\0') {
        if (map[i] != '\n' && map[i] != ' '
            && map[i] != '#' && map[i] != 'X'
            && map[i] != 'P' && map[i] != 'O')
            return (84);
        if (map[i] == 'P')
            count = count + 1;
        i = i + 1;
    }
    if (error_box_hole(map) == 84 || count != 1)
        return (84);
    return (0);
}

int error(int ac, char **av, char *map)
{
    if (ac != 2 || av[1] == NULL) {
        help();
        return (84);
    }
    if (check(map) == 84) {
        help();
        return (84);
    }
}

int sokoban(int ac, char **av)
{
    struct map *map = malloc(sizeof(struct map));
    map->size = stat_map(av[1]);
    char *buffer = malloc(sizeof(char) * (map->size + 1));
    map->fd = open(av[1], O_RDONLY);

    buffer[map->size] = '\0';
    if (map->fd < 0)
        return (84);
    map->ret = read(map->fd, buffer, map->size);
    if (map->ret == 0)
        return (84);
    if (error(ac, av, buffer) == 84)
        return (84);
    game(buffer);
    free(buffer);
    free(map);
    return (0);
}