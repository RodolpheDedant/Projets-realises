/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** main.c
*/

#include "my.h"
#include "sokoban.h"

int main(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        help();
        return (0);
    }
    return (sokoban(ac, av));
}