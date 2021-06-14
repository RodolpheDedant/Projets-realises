/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** choice.c
*/

#include "mysh.h"
#include "my.h"

int condition(char **lib, char *buffer)
{
    int idx = 0;
    int i = 0;
    int y = 0;

    while (lib[i] != NULL && my_strcmp(buffer, lib[i], ' ') != 0) {
        while (lib[i][idx] != '\0' && buffer[y] != '\0') {
            idx = idx + 1;
            y = y + 1;
        }
        i = i + 1;
        idx = 0;
        y = 0;
    }
    return (i);
}

int search_chev(char *buf)
{
    int i = 0;
    int count = 0;

    while (buf[i] != '\0') {
        if (buf[i] == '<' && buf[i + 1] == '<')
            count = 2;
        i++;
    }
    return (count);
}

int choice(char *buffer, char **env, mysh_t *mysh)
{
    int (*tabsh[])(char *, char **, mysh_t *) = {&do_cd, &do_env, &do_exit,
    &do_setenv, &do_unsetenv};
    char *lib[] = {"cd", "env", "exit", "setenv", "unsetenv", NULL};
    int i = condition(lib, buffer);

    if (lib[i] == NULL)
        command_dyn(buffer, mysh->my_env);
    else if (tabsh[i](buffer, env, mysh) == 2)
        return (2);
    return (0);
}

int my_chev(char **com, char *buf, mysh_t *mysh, char **env)
{
    int ret = 0;

    my_exec_chev(buf);
    ret = choice(com[0], env, mysh);
    return (ret);
}

int choice_command(char *buffer, char **env, mysh_t *mysh)
{
    int ret = 0;
    char **command = cutstr(buffer, ';');
    char *buf = NULL;
    char **com = NULL;

    for (int i = 0; command[i] != NULL; i++) {
        buf = clean_str(command[i]);
        if (search_chev(buf) == 2) {
            com = cutstr(command[i], '<');
            ret = my_chev(com, buf, mysh, env);
            del_tab(com);
        } else
            ret = choice(buf, env, mysh);
        if (ret == 2)
            return (2);
    }
    my_printf("$> ");
    return (0);
}