/*
** EPITECH PROJECT, 2018
** matchstick
** File description:
** matchstick
*/

#include <stdlib.h>
#include "matchstick.h"

char **create_map(int lines, int max_sticks)
{
    char **map;
    int i = 0;
    int j = 0;
    int sticks = 0;

    map = malloc(sizeof(char *) * lines);
    while (i < lines) {
        map[i] = malloc(sizeof(char) * max_sticks);
        sticks = 1 + i * 2;
        while (j < max_sticks) {
            map[i][j] = 0;
            j++;
        }
        j = (max_sticks - sticks) / 2;
        while (sticks != 0) {
            map[i][j++] = '|';
            sticks--;
        }
        i++;
    }
    return (map);
}

void draw_map(map_t *map)
{
    int i = 0;
    int j = 0;
    char c;

    while (i < map->lines + 2) {
        j = 0;
        while (j < map->stick + 2) {
            if (j == 0 || j == map->stick + 1 || i == 0 ||
                i == map->lines + 1)
                my_putchar('*');
            else
                my_putchar((c = map->tab[i - 1][j - 1]) ? c : ' ');
            j++;
        }
        my_putchar('\n');
        i++;
    }
}

int empty(map_t *map)
{
    int i = 0;
    int j = 0;

    while (i < map->lines) {
        j = 0;
        while (j < map->stick) {
            if (map->tab[i][j] == '|')
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

int matches_gestion(map_t *map, int line)
{
    int i = 0;
    int matches = 0;

    while (i < map->stick) {
        matches += map->tab[line][i] == '|' ? 1 : 0;
        i++;
    }
    return (matches);
}

void delete_matches(map_t *map, int line, int matches, int player)
{
    int i = 0;
    char *c;

    my_putstr(player == 1 ? "Player" : "AI");
    my_putstr(" removed ");
    my_putnbr(matches);
    my_putstr(" match(es) from line ");
    my_putnbr(line);
    my_putchar('\n');
    i = map->stick;
    while (i >= 0 && matches != 0) {
        if (*(c = &map->tab[line - 1][i]) == '|') {
            matches--;
            *c = '\0';
        }
        i--;
    }
}