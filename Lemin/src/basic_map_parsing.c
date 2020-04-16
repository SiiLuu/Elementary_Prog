/*
** EPITECH PROJECT, 2018
** lemin
** File description:
** basic_map_parsing
*/

#include "my.h"

char **check_tunnels(char **tab, int i, int j)
{
    static unsigned int compt = 0;

    if (tab[i][0] == '#' && tab[i + 1] == NULL)
        tab[i][0] = NULL;
    while (tab[i + 1] != NULL && tab[i + 1][j] != '\0') {
        if (tab[i][j] == '-') {
            my_printf("#tunnels\n");
            compt = 1;
        }
        if (compt == 1)
            break;
        j++;
    }
    return (tab);
}

char *end_print(char **tab, int i, char *str)
{
    int temp = i;

    while (my_strcmp(tab[i], "##end"))
        i++;
    str = tab[i + 1];
    my_printf("##end\n%s\n", tab[i + 1]);
    return (str);
}

void check_end(char **tab, int i, int j)
{
    int temp = i;
    char *str;

    str = end_print(tab, i, str);
    while (tab[i] != NULL) {
        if (tab[i][0] == '#' && tab[i + 1] != NULL)
            i++;
        check_tunnels(tab, i, j);
        if (tab[i + 1] == NULL) {
            my_printf("%s", tab[i]);
            break;
        }
        else
            if (my_strcmp(tab[i], str) && my_strcmp(tab[i], "##end"))
                my_printf("%s\n", tab[i]);
        i++;
        j = 0;
    }
}

int check_start(char **tab, int i)
{
    if (!my_strcmp(tab[i], "##start")) {
        my_printf("##start\n");
        i++;
        my_printf("%s\n", tab[i]);
        i++;
    }
    return (i);
}

void basic_map_parsing(char **tab)
{
    int i = 0;
    int j = 0;
    int compt = 0;

    i = ants(i, tab);
    for (; tab[i][0] == '#' && tab[i][1] != '#'; i++);
    while (tab[i][0] != '#') {
        if (compt == 0)
            my_printf("#rooms\n");
        compt = 1;
        my_printf("%s\n", tab[i]);
        i++;
    }
    if (tab[i][0] == '#' && compt == 0)
        my_printf("#rooms\n");
    i = check_start(tab, i);
    check_end(tab, i, j);
}