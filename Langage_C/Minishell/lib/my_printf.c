/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** my_printf.c
*/

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "../include/my.h"

int print_str_tab(char *str, va_list *ap, int b)
{
    static void (*tabfnprintf[])(va_list *) = {&put_d_or_i, &put_s, &put_c,
    &put_d_or_i, &put_u};
    static char lib[] = "dsciu";
    int y = 0;

    while (lib[y] != '\0' && str[b] != lib[y])
        y = y + 1;
    if (lib[y] == '\0')
        return (0);
    tabfnprintf[y](ap);
    return (1);
}

int my_printf(char *str, ...)
{
    int b = 0;
    va_list ap;

    va_start(ap, str);
    while (str[b] != '\0') {
        if (str[b] == '%' && print_str_tab(str, &ap, b + 1) == 1)
            b = b + 1;
        else
            my_putchar(str[b]);
        b = b + 1;
    }
    va_end(ap);
    return (0);
}