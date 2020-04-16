/*
** EPITECH PROJECT, 2018
** dante
** File description:
** generator / main
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

void free_tab(char **tab, char **argv)
{
    int	i = 0;

    while (i != atoi(argv[2])) {
        free(tab[i]);
        i++;
    }
    free(tab);
}

void display_array(char **maze, int y)
{
    for (int j = 0; j != y; j++)
        (j != (y - 1)) ? printf("%s\n", maze[j]) : printf("%s", maze[j]);
}

char **maze_allocate(char **maze, int y, int x)
{
    if ((maze = malloc(sizeof(char *) * y)) == NULL)
        exit(84);
    for (int k = 0; k != y; k++)
        if ((maze[k] = malloc(sizeof(char) * (x + 1))) == NULL)
            exit (84);
    return (maze);
}

char **basic_maze(char **tab)
{
    int i = 0;
    int x = atoi(tab[1]);
    int y = atoi(tab[2]);
    char **maze = NULL;

    maze = maze_allocate(maze, y, x);
    for (int j = 0; j != y; j++) {
        i = 0;
        for (; i != x; i++)
            if (j == 0 || i == 0 || (j == y - 1 && i == x - 1))
                maze[j][i] = '*';
            else if ((j % 2 == 0) && (i % 2 == 0))
                maze[j][i] = '*';
            else
                maze[j][i] = 'X';
        maze[j][i] = '\0';
    }
    return (maze);
}