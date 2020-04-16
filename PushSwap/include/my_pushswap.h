/*
** EPITECH PROJECT, 2018
** my_pushswap
** File description:
** my_pushswap.h
*/

#include "struct.h"

#ifndef _MY_PUSHSWAP_H_
# define _MY_PUSHSWAP_H_

void my_putchar(char c);
void my_putstr(char *str);
void my_putnbr( int nb);
int chars_errors(char *str);
int my_atoi(char *str);
void free_list(list_t **list);
int list_size(list_t *list);
int add_start_list(list_t **list, int nb);
int add_end_list(list_t **list, int nb);
int sort_gestion(list_t **list);
void push(list_t **l_a, list_t **l_b);
void rotate(list_t **l_a);
int calc(list_t *list);
void my_pushswap2(list_t **l_a, list_t **l_b);
void my_pushswap(list_t **l_a, list_t **l_b);

#endif