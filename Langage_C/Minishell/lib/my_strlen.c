/*
** EPITECH PROJECT, 2020
** my_strlen
** File description:
** program
*/
#include <stdio.h>

int my_strlen(char const *str)
{
    int a;

    a = 0;
    while (str[a] != '\0') {
        a = a + 1;
    }
    return (a);
}
