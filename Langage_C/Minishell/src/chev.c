/*
** EPITECH PROJECT, 2020
** Project_C
** File description:
** chev.c
*/

#include "my.h"
#include "mysh.h"

char *my_get_line(void)
{
    size_t size;
    char *buf = NULL;
    int ret = getline(&buf, &size, stdin);

    if (buf == NULL || ret <= 0)
        return (NULL);
    return (buf);
}

void chev(int i, char **end)
{
    char *current_command = NULL;

    while (1) {
        my_printf("? ");
        current_command = my_get_line();
        if (current_command == NULL)
            return;
        if (my_strcmp(end[i], current_command, '\n') == 0)
            return;
    }
    free(current_command);
}

void my_exec_chev(char *buf)
{
    char **args = cutstr(buf, ' ');

    if (tab(args) < 3)
        my_printf("Invalid null command.\n");
    else {
        chev(tab(args) - 1, args);
    }
    del_tab(args);
}