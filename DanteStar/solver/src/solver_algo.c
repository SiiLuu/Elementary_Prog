/*
** EPITECH PROJECT, 2018
** dante
** File description:
** solver / main
*/

#include "my.h"

int find_path(int x, int y, char **maze, char *buff)
{
    if (x < 0 || x > my_strlen(buff) - 1 || y < 0 || y > len_height(buff) - 1)
        return (0);
    if ((x == (my_strlen(buff) - 1) && (y == (len_height(buff) - 1)))) {
        maze[y][x] = 'o';
        return (1);
    }
    if (maze[y][x] != '*')
        return (0);
    maze[y][x] = 'o';
    if (find_path(x, y - 1, maze, buff) == 1)
        return (1);
    if (find_path(x + 1, y, maze, buff) == 1)
        return (1);
    if (find_path(x, y + 1, maze, buff) == 1)
        return (1);
    if (find_path(x - 1, y, maze, buff) == 1)
        return (1);
    maze[y][x] = '*';
    return (0);
}