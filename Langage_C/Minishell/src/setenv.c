/*
** EPITECH PROJECT, 2020
** Minishell2
** File description:
** setenv.c
*/

#include "mysh.h"
#include "my.h"

char *my_strcpy_env(char *dest, char const *src)
{
    int i = 0;

    while (src[i] != '\0' && src[i] != '\n') {
        dest[i] = src[i];
        i = i + 1;
    }
    dest[i] = '=';
    dest[i + 1] = '\0';
    return (dest);
}

char **fill_tab(char **env, char **old_env, char *buffer, int size)
{
    int i = 0;

    while (old_env[i] && i < size) {
        env[i] = malloc(sizeof(char) * (len_str(old_env[i]) + 1));
        my_strcpy(env[i], old_env[i]);
        i++;
    }
    if (i >= size)
        return (env);
    else {
        env[i] = malloc(sizeof(char) * (len_str(buffer) + 2));
        my_strcpy_env(env[i], buffer);
        i++;
    }
    env[i] = NULL;
    return (env);
}

char **fill_tab_bis(char **env, char **old_env, char **buffer, int size)
{
    int i = 0;
    int size_bis = len_str(buffer[1]) + len_str(buffer[2]);

    while (old_env[i] && i < size) {
        env[i] = malloc(sizeof(char) * (len_str(old_env[i]) + 1));
        my_strcpy(env[i], old_env[i]);
        i++;
    }
    if (i >= size)
        return (env);
    else {
        env[i] = malloc(sizeof(char) * (size_bis + 3));
        my_strcpy_env(env[i], buffer[1]);
        my_strcat(env[i], buffer[2]);
        i++;
    }
    env[i] = NULL;
    return (env);
}

char **my_realloc(int size, char **env, char **buffer, int choice)
{
    char **old_env = new_env(env);
    del_tab(env);
    env = malloc(sizeof(char *) * (size + 2));
    if (choice == 1)
        fill_tab(env, old_env, buffer[1], size);
    else
        fill_tab_bis(env, old_env, buffer, size);
    del_tab(old_env);
    return (env);
}

int do_setenv(char *buffer, char **env, mysh_t *mysh)
{
    char **setenv = cutstr(buffer, ' ');
    int size = tab(mysh->my_env) + 1;

    if (len_tab_bis(buffer, ' ') == 1)
        print_env(mysh->my_env);
    else if (len_tab_bis(buffer, ' ') == 2)
        mysh->my_env = my_realloc(size, mysh->my_env, setenv, 1);
    if (len_tab_bis(buffer, ' ') == 3)
        mysh->my_env = my_realloc(size, mysh->my_env, setenv, 2);
    del_tab(setenv);
    return (0);
}