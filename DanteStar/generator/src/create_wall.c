/*
** EPITECH PROJECT, 2018
** dante
** File description:
** generator / main
*/

#include "my.h"
#include <time.h>

int random_nbr(int min, int max)
{
    return ((rand() % (max - min)) + min);
}

char **create_wall(char **maze, char **argv, int y, int x)
{
    int nbr = 0;

    while (y != atoi(argv[2] - 1)) {
        if (y > atoi(argv[2]))
            break;
        nbr = random_nbr(0, 2);
        if (maze[y] != NULL && maze[y][x] == '*') {
            (nbr == 0) ? (maze[y - 1][x] = '*') : (maze[y][x - 1] = '*');
        }
        x += 2;
        if (x > atoi(argv[1])) {
            x = 2;
            y += 2;
        }
    }
    return (maze);
}

char **generate_lab(char **maze, char **argv)
{
    int x = 2;
    int y = 2;
    int nbr = 0;

    maze = basic_maze(argv);
    if (atoi(argv[1]) <= 3 || atoi(argv[2]) <= 3) {
        maze = small_maze(maze, argv);
        return (maze);
    }
    if (atoi(argv[1]) <= 1 || atoi(argv[2]) <= 1)
        return (maze);
    srand(time(NULL));
    maze = create_wall(maze, argv, y, x);
    y = atoi(argv[2]) - 1;
    x = atoi(argv[1]) - 1;
    nbr = random_nbr(0, 2);
    (nbr == 0) ? (maze[y - 1][x] = '*') : (maze[y][x - 1] = '*');
    return (maze);
}

char **generate_lab_imperfect(char **maze, char **argv)
{
    int y = atoi(argv[2]) - 1;

    maze = generate_lab(maze, argv);
    for (int x = 0; x != (atoi(argv[1]) - 1); x++)
        maze[y][x] = '*';
    return (maze);
}

char **small_maze(char **maze, char **argv)
{
    int x = 0;

    if ((atoi(argv[2]) == 2) && (atoi(argv[1]) != 1))
        for (x = 1; x != (atoi(argv[1])); x++)
            maze[0][x] = 'X';
    return (maze);
}