/*
** EPITECH PROJECT, 2020
** nbr
** File description:
** nbr
*/

#include <limits.h>

void less_line(int *e, int *i, char const *str)
{
    while (48 > str[*i] || 57 < str[*i]) {
        if (str[*i] == 45)
            *e = *e + 1;
        *i = *i + 1;
    }
}

int my_getnbr(char const *str)
{
    int i = 0;
    int nb = 0;
    int y = 1;
    int e = 0;

    less_line(&e, &i, str);
    if (e % 2 == 1)
        y = y * (-1);
    while (48 <= str[i] && str[i] < 58) {
        if (INT_MAX - nb * 10 < str[i] - 48) {
            return (0);
        } else {
            nb = nb * 10 + (str[i] - 48);
        }
        i = i + 1;
    }
    nb = nb * y;
    return (nb);
}
