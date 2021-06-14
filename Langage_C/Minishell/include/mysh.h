/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** generator.h
*/

#ifndef MYSH_H
#define MYSH_H

#include <stddef.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

typedef struct mysh {
    char **my_env;
    int status;
} mysh_t;

int mysh(char **av, char **env);
int choice_command(char *buffer, char **env, mysh_t *mysh);
void put(int sig);
int do_cd(char *buffer, char **env, mysh_t *mysh);
int do_env(char *buffer, char **env, mysh_t *mysh);
int do_exit(char *buffer, char **env, mysh_t *mysh);
int do_setenv(char *buffer, char **env, mysh_t *mysh);
int do_unsetenv(char *buffer, char **env, mysh_t *mysh);
char **new_env(char **env);
int len_tab_bis(char *str, char c);
int tab(char **str);
int len_str(char *str);
void print_env(char **env);
int command_dyn(char *buffer, char **env);
int search(char **env, char *str, int nb);
int search_env(char **env, char *str, int nb);
void cd_home(char **env);
void cd(char **env, char *directory);
char *my_realloc_char(char *env, int size);
void my_exec_chev(char *buf);

#endif