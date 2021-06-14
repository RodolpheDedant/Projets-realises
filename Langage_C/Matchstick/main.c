/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** main.c
*/

#include "matchstick.h"
#include "my.h"

int check(char *str)
{
    int i = 0;
    int count = 0;

    while (str[i] != '\0') {
        if (str[i] > 57 || str[i] < 48)
            count = count + 1;
        i = i + 1;
    }
    return (count);
}

void usage(void)
{
    my_printf("USAGE\n\t./matchstick n max\n");
}

int main(int ac, char **av)
{
    if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        usage();
        return (0);
    }
    if (ac != 3)
        return (84);
    if (check(av[1]) != 0 || check(av[2]) != 0)
        return (84);
    return (matchstick(av));
}