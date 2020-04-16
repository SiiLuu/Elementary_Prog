/*
** EPITECH PROJECT, 2018
** dante
** File description:
** solver / main
*/

#include "my.h"

int main(int ac, char **av)
{
    int fd = 0;
    char *buff = NULL;
    char **maze = NULL;
    struct stat filepath;

    if (ac != 2)
        return (84);
    stat(av[1], &filepath);
    if ((buff = malloc(sizeof(char *) * filepath.st_size)) == NULL)
        exit(84);
    if ((fd = open(av[1], O_RDONLY)) == -1)
        exit(84);
    read(fd, buff, filepath.st_size);
    maze = string_to_tab(buff, maze);
    if ((find_path(0, 0, maze, buff)) == 1)
        maze = show_tab(maze);
    else
        printf("no solution found");
    close(fd);
    return (0);
}