/*
** EPITECH PROJECT, 2020
** cmp
** File description:
** cmp
*/
#include <unistd.h>

int my_strlen_bis(char const *str, char c)
{
    int i = 0;

    while (str[i] != '\0' && str[i] != c)
        i = i + 1;
    return (i);
}

int my_strcmp(char const *s1, char const *s2, char c)
{
    int res = 0;
    int i = 0;

    if (my_strlen_bis(s1, c) != my_strlen_bis(s2, c))
        return (1);
    while ((s1[i] != '\0' && s1[i] != c) && (s2[i] != '\0' && s1[i] != c)) {
        res = (s1[i] - 48) - (s2[i] - 48) + res;
        i = i + 1;
    }
    return (res);
}
