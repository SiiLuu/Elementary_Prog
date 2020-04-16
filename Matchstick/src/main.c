/*
** EPITECH PROJECT, 2018
** matchstick
** File description:
** matchstick
*/

#include <stdlib.h>
#include <time.h>
#include "matchstick.h"

static void free_map(map_t *map)
{
    int i = 0;

    while (i < map->lines) {
        free(map->tab[i]);
        i++;
    }
    free(map->tab);
    free(map);
}

static map_t *initialize_map(int lines, int matches)
{
    map_t *map;

    map = malloc(sizeof(map_t));
    map->stick = 1 + (lines - 1) * 2;
    map->tab = create_map(lines, map->stick);
    map->lines = lines;
    map->match = matches;
    map->return_value = 0;
    return (map);
}

int main(int ac, char **av)
{
    int status;
    map_t *map = NULL;

    if (ac != 3 || my_atoi(av[1]) < 1 || my_atoi(av[1]) > 99 ||
        !(my_atoi(av[1])) || !(my_atoi(av[2])) || my_atoi(av[2]) < 0)
        return (84);
    map = initialize_map(my_atoi(av[1]), my_atoi(av[2]));
    srand(time(NULL));
    draw_map(map);
    player(map);
    status = map->return_value;
    if (status == -1)
        return (0);
    free_map(map);
    return (status);
}