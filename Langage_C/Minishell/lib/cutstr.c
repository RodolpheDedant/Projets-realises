/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** cutstr.c
*/

#include <stdio.h>
#include <stdlib.h>

void del_tab(char **str)
{
    int i = 0;

    while (str[i] != NULL) {
        free(str[i]);
        i = i + 1;
    }
    free(str);
}

char *my_strcpy_bis(char *src, char *dest, char c, int *i)
{
    int idx = 0;

    while (src[*i] != '\0' && src[*i] != c) {
        dest[idx] = src[*i];
        *i = *i + 1;
        idx = idx + 1;
    }
    dest[idx] = '\0';
    return (dest);
}

int len_tab(char *str, char c)
{
    int i = 0;
    int count = 1;

    while (str[i] != '\0') {
        if (str[i] == c)
            count = count + 1;
        i = i + 1;
    }
    return (count);
}

int len_string(char *str, int i, char c)
{
    int count = 0;

    while (str[i] != '\0' && str[i] != c) {
        i = i + 1;
        count = count + 1;
    }
    return (count);
}

char **cutstr(char *str, char c)
{
    int i = 0;
    int j = 0;
    char **tab = malloc(sizeof(char *) * (len_tab(str, c) + 1));

    while (str[i] != '\0') {
        if (str[i] == c)
            i = i + 1;
        if (str[i] != c && len_string(str, i, c) != 0) {
            tab[j] = malloc(sizeof(char) * (len_string(str, i, c) + 1));
            my_strcpy_bis(str, tab[j], c, &i);
            j = j + 1;
        }
    }
    tab[j] = NULL;
    return (tab);
}