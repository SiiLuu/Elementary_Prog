/*
** EPITECH PROJECT, 2018
** my_pushswap
** File description:
** list_gestion.
*/

#include <stdlib.h>
#include "../include/my_pushswap.h"

int list_size(list_t *list)
{
    int i = 0;

    while (list != NULL) {
        i++;
        list = list->next;
    }
    return (i);
}

void free_list(list_t **list)
{
    list_t *free_this;

    while (*list != NULL) {
        free_this = *list;
        *list = (*list)->next;
        free(free_this);
    }
}

int add_start_list(list_t **list, int nb)
{
    list_t *new_nb;

    new_nb = malloc(sizeof(list_t));
    if (new_nb == NULL)
        return (1);
    new_nb->nb = nb;
    new_nb->next = *list;
    *list = new_nb;
    return (0);
}

int add_end_list(list_t **list, int nb)
{
    list_t *new_nb;
    list_t *temp;

    new_nb = malloc(sizeof(list_t));
    if (new_nb == NULL)
        return (1);
    new_nb->nb = nb;
    new_nb->next = NULL;
    if (*list == NULL)
        *list = new_nb;
    else {
        temp = *list;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new_nb;
    }
    return (0);
}

int sort_gestion(list_t **list)
{
    list_t *temp = *list;
    list_t *temp2 = *list;

    while (temp2 != NULL) {
        while (temp != NULL) {
            if (temp2->nb <= temp->nb)
                temp = temp->next;
            else
                return (1);
        }
        temp2 = temp2->next;
        temp = temp2;
    }
    return (0);
}