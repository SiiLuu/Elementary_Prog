/*
** EPITECH PROJECT, 2018
** my_getnextline
** File description:
** GNL.
*/

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

char *get_next_line(const int fd)
{
    static char buff[1 + 1];
    char *line = NULL;
    int ret = 0;
    int j = 0;

    buff[0] = '\0';
    if ((ret = read(fd, buff, READ_SIZE)) == -1)
        return (NULL);
    if (buff[0] == '\0')
        return (NULL);
    line = malloc(sizeof(char) * (ret + 1));
    while (buff[j] != '\n' && buff[j] != '\0') {
        line[j] = buff[j];
        j++;
    }
    line[j] = '\0';
    return (line);
}