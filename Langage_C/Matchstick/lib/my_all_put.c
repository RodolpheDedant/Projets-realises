/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** my_all_put.c
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i = i + 1;
    }
}

int my_put_nbr(int nb)
{
    int n;

    if (nb > 9) {
        n = nb % 10;
        nb = nb / 10;
        my_put_nbr(nb);
        my_putchar(n + 48);
    } else if (nb >= 0 && nb < 10) {
        my_putchar(nb + 48);
    }
    if (nb < 0) {
        my_putchar('-');
        n = (nb % 10) * -1;
        my_put_nbr((nb / 10) * -1);
        my_putchar(n + 48);
    }
    return (0);
}

int my_put_pos(unsigned int nb)
{
    int n;

    if (nb > 9) {
        n = nb % 10;
        nb = nb / 10;
        my_put_pos(nb);
        my_putchar(n + 48);
    } else if (nb >= 0 && nb < 10) {
        my_putchar(nb + 48);
    }
    return (0);
}