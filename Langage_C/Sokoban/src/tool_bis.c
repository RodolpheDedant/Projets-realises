/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** tool.c
*/

#include "my.h"

void f_arr_bis(char **arr, int nb_rows)
{
    int i = 0;

    while (i < nb_rows) {
        free(arr[i]);
        i = i + 1;
    }
    free(arr);
}

char *my_strcpybisi(char *dest, char *str)
{
    int idx = 0;
    static int i = 0;

    while ((str[i] != '\0' && str[i] != '\n')) {
        dest[idx] = str[i];
        i = i + 1;
        idx = idx + 1;
    }
    dest[idx] = '\0';
    if (str[i] == '\n')
        i++;
    return (dest);
}

int count_word_bis(char *str)
{
    int count = 1;
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == '\n')
            count = count + 1;
        i = i + 1;
    }
    return (count);
}

int count_char_bis(char *str)
{
    int nb_char = 0;
    static int idx = 0;

    while (str[idx] != '\0' && str[idx] != '\n') {
        nb_char = nb_char + 1;
        idx = idx + 1;
    }
    while (str[idx] == '\n')
        idx++;
    return (nb_char);
}

char **cut_str_bis(char *str)
{
    int nb_word = count_word_bis(str);
    int i = 0;
    int nb_char = 0;
    int idx = 0;
    char **tab = malloc(sizeof(char *) * (nb_word + 1));

    while (i < nb_word) {
        nb_char = count_char_bis(str);
        if (nb_char != 0) {
            tab[i] = malloc(sizeof(char) * (nb_char + 1));
            my_strcpybisi(tab[i], str);
        }
        nb_char = 0;
        i = i + 1;
    }
    return (tab);
}