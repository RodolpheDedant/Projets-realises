/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** flag_i_d_s_c_u.c
*/

#include "../include/my.h"
#include <stdarg.h>

void put_d_or_i(va_list *ap)
{
    int i = va_arg(*ap, int);
    my_put_nbr(i);
}

void put_s(va_list *ap)
{
    char *str = va_arg(*ap, char *);
    my_putstr(str);
}

void put_c(va_list *ap)
{
    int c = va_arg(*ap, int);
    my_putchar(c);
}

void put_u(va_list *ap)
{
    unsigned int u = va_arg(*ap, unsigned int);
    my_put_pos(u);
}