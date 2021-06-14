/*
** EPITECH PROJECT, 2020
** cat
** File description:
** cat
*/

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int y = my_strlen(dest);

    while (src[i] != '\0') {
        dest[y + i] = src[i];
        i = i + 1;
    }
    dest[y + i] = '\0';
    return (dest);
}
