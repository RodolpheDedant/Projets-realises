/*
** EPITECH PROJECT, 2020
** cmp
** File description:
** cmp
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int res = 0;
    int i = 0;
    int y = 0;

    while (i < n && s1[i] != '\0' && s2[y] != '\0') {
        if (s1[i] != s2[y]) {
            res = (s1[i] - 48) - (s2[i] - 48) + res;
        }
        i = i + 1;
        y = y + 1;
    }
    return (res);
}
