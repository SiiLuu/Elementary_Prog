/*
** EPITECH PROJECT, 2018
** BSQ
** File description:
** Find the biggest square in a two dimension map.
*/

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include "bsq.h"

void solve_tab(char **array)
{
    int i = 0;
    int j = 0;

    while (array[i][j] != '\0') {
        if (array[i][j] == '.')
            array[i][j] = 'x';
        else if (array[i][j] == 'o')
            j++;
        else {
            j = 0;
            i++;
        }
    }
}

void use_algo(char **array)
{
    solve_tab(array);
}

char **rep_str_to_tab(char *str)
{
    int i = 0;
    int x = 0;
    int y = 0;
    char **array;

    array = malloc(sizeof(char *) * len_height(str));
    for (int g = 0; g <= len_height(str); g++)
        array[g] = malloc(sizeof(char) * len_width(str) + 2);
    while (str[i] != '\0') {
        if (str[i] == '\n') {
            y++;
            i++;
            x = 0;
    	}
    	array[y][x] = str[i];
    	x++;
    	i++;
    }
    use_algo(array);
    return (array);
}

void display_tab(char *str)
{
    int i = 0;
    char **array;

    array = rep_str_to_tab(str);
    while (str[i] != '\n')
        i++;
    i++;
    while (i != len_height(str)) {
    	my_putstr(array[i]);
    	my_putchar('\n');
    	i++;
    }
}

int main(int ac, char **av)
{
    int fd = 0;
    int size = 1;
    char *buff;
    struct stat filepath;

    if (ac != 2)
        return (84);
    stat(av[1], &filepath);
    buff = malloc(sizeof(char *) * filepath.st_size);
    fd = open_file(av[1]);
    size = read(fd, buff, filepath.st_size);
    display_tab(buff);

    close(fd);
    return (0);
}