/*
** EPITECH PROJECT, 2020
** Minishell2
** File description:
** utils.c
*/

#include <stddef.h>

int len_tab_bis(char *str, char c)
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

int tab(char **str)
{
    int i = 0;
    int count = 0;

    while (str[count] != NULL) {
        if (str[count][i] == '\0')
            i = i + 1;
        i = 0;
        count = count + 1;
    }
    return (count);
}

int len_str(char *str)
{
    int i = 0;
    int count = 0;

    while (str[i] != '\0') {
        i = i + 1;
        count = count + 1;
    }
    return (count);
}