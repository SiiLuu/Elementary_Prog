/*
** EPITECH PROJECT, 2018
** use_fonc
** File description:
** tools.
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int open_file(char *path)
{
    int fd = 0;

    if ((fd = open(path, O_RDONLY)) == -1)
        return (84);
    return (fd);
}