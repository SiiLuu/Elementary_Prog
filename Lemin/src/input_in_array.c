/*
** EPITECH PROJECT, 2019
** my_input_in_array
** File description:
** input
*/

#include "my.h"

int my_room_in_array(file_error_t *file_error, char **array)
{
    int i = 0;
    int k = 1;
    int j = 0;
    int a = 0;

    for (k = 1; k <= file_error->room_nbr; k++) {
        if (array[k][0] != '#' && flen(array[k]) != -1) {
            file_error->room_name[j] = malloc(sizeof(char) * flen(array[k]));
            for (i = 0; array[k][i] != '\0'; i++)
                file_error->room_name[j][i] = array[k][i];
            file_error->room_name[j][i] = '\0';
            j++;
        }
        else
            file_error->comment += 1;
        i = 0;
    }
    file_error->room_name[j] = NULL;
}

void my_link_in_array(file_error_t *file_error, char **array)
{
    int j = 0;
    int i = 0;
    int k = file_error->room_nbr + 1;
    int len = 0;

    for (k = file_error->room_nbr + 1; array[k] != NULL; k++) {
        len = flen(array[k]);
        if (array[k][0] != '#' && len != -1) {
            file_error->link_name[j] = malloc(sizeof(char) * len);
                for (i = 0; array[k][i] != '\0'; i++)
                    file_error->link_name[j][i] = array[k][i];
            file_error->link_name[j][i] = '\0';
            j++;
        }
        else
            file_error->comment_link += 1;
        i = 0;
    }
    file_error->link_name[j] = NULL;
}