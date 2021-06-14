/*
** EPITECH PROJECT, 2020
** Project_C
** File description:
** clean_str.c
*/

#include <stdlib.h>

int my_cleanlen(char *str)
{
    int i = 0;
    int count = 0;

    while (str[i] != '\0' && str[i] <= ' ')
        i++;
    while (str[i] != '\0') {
        if (str[i] > ' ')
            count = count + 1;
        else if ((str[i] == ' ' || str[i] == '\t') && str[i + 1] > ' ') {
            count = count + 1;
        }
        i = i + 1;
    }
    return (count);
}

char *clean_str(char *str)
{
    int size = my_cleanlen(str);
    char *clean = malloc(sizeof(char) * (size + 1));
    int i = 0;
    int idx = 0;

    while (str[i] != '\0' && str[i] <= ' ')
        i++;
    while (str[i] != '\0' || idx < size) {
        if (str[i] > ' ')  {
            clean[idx] = str[i];
            idx++;
        } else if ((str[i] == ' ' || str[i] == '\t') && str[i + 1] > ' ') {
            clean[idx] = ' ';
            idx++;
        }
        i++;
    }
    clean[idx] = '\0';
    return (clean);
}