/*
** EPITECH PROJECT, 2019
** lem_in
** File description:
** coord room error
*/

#include "my.h"

int check_number(file_error_t *file_error, int k, int i)
{
    if (file_error->room_name[k][i] >= 47 && file_error->room_name[k][i] <= 57)
        return (0);
    else
        return (84);
}

int coord_error_2(file_error_t *file_error, int k, int i, int space)
{
    int error = 0;

    if (file_error->room_name[k][i] == ' ' &&
        file_error->room_name[k][i + 1] != '#')
        space += 1;
    if (space >= 1 && file_error->room_name[k][i] != ' ')
        error = check_number(file_error, k, i);
    if (error == 84) {
        file_error->error_status = 84;
        return (file_error->line_error = k - 1);
    }
    return (0);
}

int coord_error(file_error_t *file_error)
{
    int k = 0;
    int i = 0;
    int space = 0;
    int error = 0;

    while (k != file_error->room - file_error->comment) {
        while (file_error->room_name[k][i] != '\0') {
            error = coord_error_2(file_error, k, i, space);
            if (file_error->error_status == 84)
                return (error);
            i++;
        }
        if (space != 2) {
            file_error->error_status = 84;
            return (file_error->line_error = k - 1);
        }
        i = 0;
        space = 0;
        k++;
    }
    return (0);
}

void print_before_error(file_error_t *file_error, char **array)
{
    int k = 0;

    while (k <= file_error->line_error + file_error->comment) {
        my_putstr(array[k]);
        my_putchar('\n');
        k++;
    }
}