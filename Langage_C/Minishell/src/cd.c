/*
** EPITECH PROJECT, 2020
** Project_C
** File description:
** cd.c
*/

#include "mysh.h"
#include "my.h"

char *cpy_env(char **env, char *str, int nb, int count)
{
    char **pwd = cutstr(str, ' ');
    int i = search(env, pwd[0], nb);

    my_strcpy(env[count], pwd[1]);
    my_strcat(env[count], &env[i][my_strlen(pwd[1]) + 1]);
    del_tab(pwd);
    return (env[count]);
}

void cd_home(char **env)
{
    int count = search(env, "HOME=", 5);

    if (chdir(&env[count][5]) == -1)
        my_printf("Not a directory.\n");

}

void cd(char **env, char *directory)
{
    if (chdir(directory) == -1)
        my_printf("%s: Not a directory.\n", directory);
}