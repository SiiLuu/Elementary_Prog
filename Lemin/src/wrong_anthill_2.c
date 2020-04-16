/*
** EPITECH PROJECT, 2019
** wrong_anthill
** File description:
** check input
*/

#include "my.h"

int command_or_comment(char **array, int k, int i)
{
    if (array[k][i] == '#' && array[k][i + 1] == '#')
        return (1);
    else if (array[k][i] == '#' && array[k][i + 1] != '#')
        return (2);
    return (0);
}

int compare_link_betwen_room(char **array)
{
    int k = 0;
    int i = 0;
    long int count = 0;

    for (k = 1; array[k] != NULL; k++) {
        for (i = 0; array[k][i] != '\0'; i++) {
            if (array[k][i] == '-')
                return (count);
        }
        count++;
        i = 0;
    }
    return (0);
}

void print_room(file_error_t *file_error)
{
    int k = 0;

    while (k != file_error->room_nbr - file_error->comment) {
        my_putstr(file_error->room_name[k]);
        my_putchar('\n');
        k++;
    }
    k = 0;
    my_putstr("\n");
    while (file_error->link_name[k] != NULL) {
        my_putstr(file_error->link_name[k]);
        my_putchar('\n');
        k++;
    }
}

int check_link_nbr(char **array)
{
    int i = 1;
    int j = 0;
    int count = 0;
    int res = 0;

    for (i = 1; array[i] != NULL; i++) {
        for (j = 0; array[i][j] != '\0'; j++) {
            if (array[i][j] == '-')
                count++;
        }
        if (count == 1)
            res++;
        count = 0;
        j = 0;
    }
    return (res);
}

int flen(char *str)
{
    int result = 0;
    int i = 0;

    if (str[0] == '#')
        return (-1);
    while (str[i] != '\0' && str[i] != '#') {
        result++;
        i++;
    }
    if (str[i] != '#')
        result += 1;
    return (result);
}