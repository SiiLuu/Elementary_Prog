/*
** EPITECH PROJECT, 2018
** my_pushswap
** File description:
** sort.
*/

#include <stdlib.h>
#include "../include/my_pushswap.h"

void push(list_t **l_a, list_t **l_b)
{
    int nb = 0;
    list_t *temp_free;

    nb = (*l_a)->nb;
    add_start_list(l_b, nb);
    temp_free = *l_a;
    *l_a = (*l_a)->next;
    free(temp_free);
}

void rotate(list_t **l_a)
{
    int nb = 0;
    list_t *temp_free;

    nb = (*l_a)->nb;
    add_end_list(l_a, nb);
    temp_free = *l_a;
    *l_a = (*l_a)->next;
    free(temp_free);
}

int calc(list_t *list)
{
    int count = 0;
    int sec_count = 0;
    int nb = 0;

    nb = list->nb;
    while (list != NULL) {
        if ((list->nb) < nb) {
            nb = list->nb;
            count = sec_count;
        }
        list = list->next;
        sec_count++;
    }
    return (count);
}

void my_pushswap2(list_t **l_a, list_t **l_b)
{
    int i = 0;
    int j = 0;

    if (list_size(*l_a) != 1) {
        j = calc(*l_a);
        while (i < j) {
            rotate(l_a);
            my_putstr("ra ");

            i++;
        }
        push(l_a, l_b);
        my_putstr("pb ");
        my_pushswap2(l_a, l_b);
    }
}

void my_pushswap(list_t **l_a, list_t **l_b)
{
    int i = 0;

    my_pushswap2(l_a, l_b);
    i = list_size(*l_b);
    while (i > 0) {
        push(l_b, l_a);
        i--;
        if (i > 0)
            my_putstr("pa ");
        else
            my_putstr("pa\n");
    }
}