/*
** EPITECH PROJECT, 2018
** matchstick
** File description:
** matchstick
*/

#include <stdlib.h>
#include "matchstick.h"

int error_message(int *matches, map_t *map, int line)
{
    if (*matches < 0) {
        my_putstr("Error: invalid input (positive number expected)\n");
        return (0);
    }
    if (*matches == 0) {
        my_putstr("Error: you have to remove at least one match\n");
        return (0);
    }
    if (*matches > map->match) {
        my_putstr("Error: you cannot remove more than ");
        my_putnbr(map->match);
        my_putstr(" matches per turn\n");
        return (0);
    }
    if (*matches > matches_gestion(map, line -1)) {
        my_putstr("Error: not enough matches on this line\n");
        return (0);
    }
}

static int analyse_matches(map_t *map, int *matches, int line)
{
    char *scan;

    my_putstr("Matches: ");
    if (!(scan = look_line()))
        return ((map->return_value = -1));
    *matches = my_atoi(scan);
    free(scan);
    if (error_message(matches, map, line) == 0)
        return (0);
    return (1);
}

static int analyse_lines(map_t *map, int *line)
{
    char *scan;

    my_putstr("Line: ");
    if (!(scan = look_line()))
        return (map->return_value = -1);
    *line = my_atoi(scan);
    free(scan);
    if (*line <= 0 || *line > map->lines) {
        my_putstr(*line > 0 ? "Error: this line is out of range\n" :
            "Error: invalid input (positive number expected)\n");
        return (1);
    }
    return (0);
}

static void robo(map_t *map)
{
    int i = 0;
    int n = 0;

    my_putstr("\nAI's turn...\n");
    while (i < map->lines) {
        if ((n = matches_gestion(map, i))) {
            delete_matches(map, i + 1, n > 1 ? (rand() % n) + 1 : 1, 2);
            break;
        }
        i++;
    }
    draw_map(map);
    if (empty(map) == 1)
        player(map);
    else {
        my_putstr("I lost... snif... but I'll get you next time!!\n");
        map->return_value = 1;
    }
}

void player(map_t *map)
{
    int lines = 0;
    int matches = 0;

    my_putstr("\nYour turn :\n");
    while (analyse_lines(map, &lines) == 1 ||
        (map->return_value == 0 &&
            analyse_matches(map, &matches, lines) == 0));
    if (map->return_value == -1)
        return ;
    delete_matches(map, lines, matches, 1);
    draw_map(map);
    if (empty(map) == 1)
        robo(map);
    else {
        my_putstr("You lost, too bad...\n");
        map->return_value = 2;
    }
}