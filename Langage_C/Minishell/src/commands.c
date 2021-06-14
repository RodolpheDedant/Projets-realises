/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** commands.c
*/

#include "mysh.h"
#include "my.h"

void print_env(char **env)
{
    for (int i = 0; env[i] != NULL; i++)
        my_printf("%s\n", env[i]);
}

int do_exit(char *buffer, char **env, mysh_t *mysh)
{
    return (2);
}

int do_env(char *buffer, char **env, mysh_t *mysh)
{
    print_env(mysh->my_env);
    return (0);
}

int do_cd(char *buffer, char **env, mysh_t *mysh)
{
    char *buf = clean_str(buffer);
    char **directory = cutstr(buf, ' ');

    if (tab(directory) > 2) {
        my_printf("cd: Too many arguments.\n");
        return (0);
    }
    if (tab(directory) == 1 || my_strcmp("~", directory[1], '\n') == 0)
        cd_home(mysh->my_env);
    else if (access(directory[1], F_OK) == -1)
        my_printf("%s: Not a directory.\n", directory[1]);
    else
        cd(mysh->my_env, directory[1]);
    return (0);
}

void put(int sig)
{
    my_printf("\n$> ");
}