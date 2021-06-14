/*
** EPITECH PROJECT, 2020
** Project_C
** File description:
** mysh.c
*/

#include "my.h"
#include "mysh.h"

int len_str_bis(char *str)
{
    int i = 0;
    int count = 0;

    while (str[i] != '\0') {
        i = i + 1;
        count = count + 1;
    }
    return (count);
}

char **envcpy(char **new_env, char **env)
{
    for (int i = 0; env[i] != NULL; i++) {
        for (int y = 0; env[i][y] != '\0'; y++) {
            new_env[i][y] = env[i][y];
        }
    }
    return (new_env);
}

char **new_env(char **env)
{
    int size = tab(env);
    char **new_env = malloc(sizeof(char *) * (size + 1));
    int i = 0;
    int x = 0;

    while (i < size) {
        new_env[i] = malloc(sizeof(char) * (len_str_bis(env[i]) + 1));
        while (x < len_str_bis(env[i])) {
            new_env[i][x] = ' ';
            x++;
        }
        new_env[i][x] = '\0';
        x = 0;
        i++;
    }
    new_env[i] = NULL;
    envcpy(new_env, env);
    return (new_env);
}

int getstring(char **env, mysh_t *mysh)
{
    size_t size = 0;
    char *buf = NULL;
    char *command = NULL;
    int ret = getline(&buf, &size, stdin);

    if (mysh->status == 0) {
        mysh->my_env = new_env(env);
        mysh->status = 1;
    }
    if (buf == NULL || buf[0] == '\n') {
        my_printf("$> ");
        return (0);
    }
    command = clean_str(buf);
    if (ret <= 0 || choice_command(buf, env, mysh) == 2) {
        my_printf("exit\n");
        del_tab(mysh->my_env);
        return (2);
    }
    return (0);
}

int mysh(char **av, char **env)
{
    int i = 0;
    mysh_t mysh;

    mysh.status = 0;
    my_printf("$> ");
    signal(SIGINT, put);
    while (i == 0) {
        if (getstring(env, &mysh) == 2)
            i = 1;
    }
    return (0);
}