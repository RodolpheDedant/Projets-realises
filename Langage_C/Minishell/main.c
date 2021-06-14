/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** main.c
*/

#include "mysh.h"

int main(int ac, char **av, char **env)
{
    if (ac != 1)
        return (84);
    return (mysh(av, env));
}