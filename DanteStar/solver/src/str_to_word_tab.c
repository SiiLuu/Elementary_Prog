/*
** EPITECH PROJECT, 2018
** dante
** File description:
** solver / main
*/

#include "my.h"

void set_line(char **maze, char *buff, int height, int len)
{
    int i = 0;
    int j = 0;
    int k = 0;

    for (i = 0; i != height; i++) {
        for (j = 0; j != len; j++) {
            if (buff[k] == '\n')
                k++;
            maze[i][j] = buff[k];
            k++;
            if (j + 1 == len)
                maze[i][j + 2] = '\0';
        }
    }
}

char **string_to_tab(char *buff, char **maze)
{
    int i = 0;
    int height = len_height(buff);
    int len = 0;

    if (height > 1)
        len = my_strlen(buff);
    else
        len = my_strlen(buff);
    maze = malloc(sizeof(char *) * (height + 1));
    for (i = 0; i != height; i++) {
        maze[i] = malloc(sizeof(char) * (len + 1));
    }
    maze[i] = NULL;
    set_line(maze, buff, height, len);
    return (maze);
}

char **show_tab(char **tab)
{
    int i = 0;

    while (tab[i] != NULL) {
        (tab[i + 1] != NULL) ? (printf("%s\n", (tab[i]))) :
        printf("%s", tab[i]);
        i++;
    }
    return (tab);
}