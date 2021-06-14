/*
** EPITECH PROJECT, 2020
** Project_C
** File description:
** utils_search.c
*/

#include "my.h"

int search(char **env, char *str, int nb)
{
    int i = 0;

    while (env[i] != NULL) {
        if (my_strncmp(env[i], str, nb) == 0)
            return (i);
        i++;
    }
    return (i);
}

int search_env(char **env, char *str, int nb)
{
    int i = search(env, str, 4);
    int count = 0;

    while (env[i][count] != '\0')
        count++;
    return (count);
}

char *my_realloc_char(char *env, int size)
{
    free(env);
    env = malloc(sizeof(char) * (size + 1));
    return (env);
}