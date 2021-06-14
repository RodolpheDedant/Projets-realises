/*
** EPITECH PROJECT, 2020
** Minishell2
** File description:
** unsetenv.c
*/

#include "mysh.h"
#include "my.h"

int verif_env(char **buffer, char **old_env, int *idx)
{
    int x = 1;

    while (buffer[x] != NULL) {
        if (my_strcmp(buffer[x], old_env[*idx], '=') == 0)
            return (1);
        x++;
    }
    return (0);
}

char **fill_tab_unset(char **env, char **old_env, char **buffer, int size)
{
    int i = 0;
    int idx = 0;

    while (old_env[idx] && i < size) {
        env[i] = malloc(sizeof(char) * (len_str(old_env[idx]) + 1));
        if (verif_env(buffer, old_env, &idx) == 0) {
            my_strcpy(env[i], old_env[idx]);
            i++;
        }
        idx++;
    }
    env[i] = NULL;
    return (env);
}

char **my_realloc_unset(int size, char **env, char **buffer)
{
    char **old_env = new_env(env);

    del_tab(env);
    env = malloc(sizeof(char *) * (size + 1));
    fill_tab_unset(env, old_env, buffer, size);
    del_tab(old_env);
    return (env);
}

int do_unsetenv(char *buffer, char **env, mysh_t *mysh)
{
    char **unsetenv = cutstr(buffer, ' ');
    int size = tab(mysh->my_env) - tab(unsetenv) + 2;

    if (len_tab_bis(buffer, ' ') == 1)
        my_printf("unsetenv: Too few arguments.\n");
    else
        mysh->my_env = my_realloc_unset(size, mysh->my_env, unsetenv);
    del_tab(unsetenv);
    return (0);
}