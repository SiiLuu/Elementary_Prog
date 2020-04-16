/*
** EPITECH PROJECT, 2018
** my_pushswap
** File description:
** push_swap.
*/

#include <stdlib.h>
#include "../include/my_pushswap.h"

int main(int ac, char **av)
{
    int i = 1;
    int sort = 0;
    list_t *l_a = NULL;
    list_t *l_b = NULL;

    if (ac == 2)
        my_putchar('\n');
    else if (ac > 2) {
        while (i < ac) {
            if (chars_errors(av[i]) == 0) {
                add_end_list(&l_a, my_atoi(av[i]));
                sort = 1;
            }
            i++;
        }
        ((sort_gestion(&l_a) == 0) ? (my_putchar('\n')) :
            ((sort == 1) ? my_pushswap(&l_a, &l_b) : (0)));
        free_list(&l_a);
        free_list(&l_b);
    }
    return (0);
}