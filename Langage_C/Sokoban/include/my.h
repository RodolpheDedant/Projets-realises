/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** my.h
*/

#ifndef MY_H
#define MY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void my_putchar(char c);
int my_putstr(char const *str);
int my_put_nbr(int nb);
int my_put_pos(int unsigned nb);
void put_d_or_i(va_list *ap);
void put_s(va_list *ap);
void put_c(va_list *ap);
void put_u(va_list *ap);
int my_printf(char *str, ...);
int my_strlen(char const *str);
char *my_strcpy(char *dest, char const *src);

#endif