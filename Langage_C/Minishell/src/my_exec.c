/*
** EPITECH PROJECT, 2020
** B-PSU-210-BDX-2-1-minishell2-rodolphe.dedant
** File description:
** my_exec.c
*/

#include "mysh.h"
#include "my.h"

void my_putstr_bis(char *str, char c)
{
    int i = 0;

    while (str[i] && str[i] != c && str[i] != ' ') {
        my_printf("%c", str[i]);
        i++;
    }
}

int check_exec(char *command, pid_t pid, char **arguments, char **env)
{
    int status = 0;

    if (pid < 0)
        return (0);
    else if (pid == 0) {
        if (execve(command, arguments, env) == -1)
            return (0);
    } else {
        waitpid(pid, &status, 0);
            if (WIFSIGNALED(status))
                return (0);
    }
    return (1);
}

int exec(char *path, char *buffer, char **env, int status)
{
    int size = my_strlen(path) + my_strlen(buffer);
    char *command = malloc(sizeof (char) * (size + 2));
    pid_t pid;
    char **arguments = cutstr(buffer, ' ');

    if (status == 0)
        my_strcpy(command, buffer);
    else {
        my_strcpy(command, path);
        command[my_strlen(path)] = '/';
        my_strcat(command, arguments[0]);
    }
    if (access(command, F_OK) == -1)
        return (0);
    pid = fork();
    if (check_exec(command, pid, arguments, env) == 0)
        return (0);
    del_tab(arguments);
    free(command);
    return (1);
}

int exec_command(char **path, char *buffer, char **env)
{
    int i = 0;
    int status = 0;

    while (path[i] != NULL) {
        if (exec(path[i], buffer, env, status) == 1) {
            return (1);
        }
        status = 1;
        i++;
    }
    return (0);
}

int command_dyn(char *buffer, char **env)
{
    int link = 0;

    while (env[link] != NULL) {
        if (my_strncmp(env[link], "PATH", 4) == 0)
            break;
        link++;
    }
    if (env[link] == NULL)
        return (0);
    char **path = cutstr(&env[link][5], ':');
    if (exec_command(path, buffer, env) == 0) {
        my_putstr_bis(buffer, '\n');
        my_printf(": Command not found.\n");
        /*for (int i = 0; env[i] != NULL; i++)
            my_printf("%s\n", env[i]);*/
    }
    return (0);
}