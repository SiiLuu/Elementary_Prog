/*
** EPITECH PROJECT, 2018
** lemin
** File description:
** lemin
*/

#include "my.h"

int check_tab(char **tab)
{
    int i = 0;
    int end = 0;

    while (tab[i] != NULL) {
        if (my_strcmp("##end", tab[i]) == 0)
            end++;
        i++;
    }
    if (end != 1)
        return (84);
    return (0);
}

void info_program(void)
{
    my_putstr("USAGE:\n\t./lem_in < [file with input]");
}

int main_loop(file_error_t *file_error)
{
    link_t **link = NULL;
    char **tab = NULL;

    tab = get_parameters(tab);
    if (check_tab(tab) == 84)
        return (84);
    if (anthill_gestion(file_error, tab) == 84)
        return (84);
    basic_map_parsing(tab);
    return (0);
}

int main(int ac, char **av)
{
    file_error_t *file_error = malloc(sizeof(file_error_t) * 1);

    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0')
        info_program();
    else {
        main_loop(file_error);
    }
    free(file_error);
    return (0);
}