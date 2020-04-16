/*
** EPITECH PROJECT, 2018
** dante
** File description:
** generator / main
*/

#include "my.h"

int main(int argc, char **argv)
{
    char **maze = NULL;

    if (main_generator(argc, argv) == 84)
        return (84);
    else {
        if (argc == 4)
            maze = generate_lab(maze, argv);
        else
            maze = generate_lab_imperfect(maze, argv);
        display_array(maze, atoi(argv[2]));
        free_tab(maze, argv);
    }
    return (0);
}