/*
** EPITECH PROJECT, 2018
** lemin
** File description:
** basic_map_parsing
*/

#include "my.h"

int ants(int i, char **tab)
{
    for (; tab[i][0] == '#'; i++);
    if (tab[i][0] <= 57 && tab[i][0] >= 48) {
        my_printf("#number_of_ants\n");
        my_printf("%s\n", tab[i]);
        i++;
    }
    return (i);
}