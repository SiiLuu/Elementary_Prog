/*
** EPITECH PROJECT, 2019
** CPE_lemin_2018
** File description:
** input gestion in the anthill file
*/

#include "my.h"

int rmv_comment(char **array, int limit)
{
    int i = 0;
    int count = 0;

    for (i = 0; i != limit; i++) {
        if (array[i][0] != '#')
            count++;
    }
    return (limit - count);
}

int ants_number(char **array, file_error_t *file_error)
{
    int k = 0;
    int i = 0;

    while (array[k][0] == '#') {
        k++;
    }
    while (array[k][i] != '\0') {
        if (array[k][i] < 48 || array[k][i] > 57) {
            file_error->ants_error = 84;
            return (84);
        }
        i++;
    }
    return (0);
}

void init_array(file_error_t *file_error, char **array)
{
    file_error->links_nbr = check_link_nbr(array);
    file_error->room_nbr = compare_link_betwen_room(array);
    file_error->room_name = malloc(sizeof(char *) * file_error->room_nbr + 1);
    file_error->link_name = malloc(sizeof(char *) * file_error->links_nbr + 1);
}

int check_room(file_error_t *file_error, char **array)
{
    int k = 0;

    while (array[k][0] == '#') {
        k++;
    }
    if (file_error->room_name[0] == NULL) {
        my_printf("#number_of_ants\n%s\n#rooms\n##start\n##end\n#tunnels",
                    array[k]);
        return (84);
    }
    return (0);
}

int anthill_gestion(file_error_t *file_error, char **array)
{
    file_error->room_name = NULL;

    init_array(file_error, array);
    if (file_error->room_nbr == 0)
        file_error->error_status = 84;
    ants_number(array, file_error);
    if (file_error->ants_error == 84) {
        my_putstr("#number_of_ants\n-1\n#rooms\n##start\n##end\n#tunnels");
        return (84);
    }
    if (my_room_in_array(file_error, array) == 84)
        return (84);
    my_link_in_array(file_error, array);
    file_error->room_nbr = (file_error->room_nbr - rmv_comment(array,
        file_error->room_nbr));
    if (check_room(file_error, array) == 84)
        return (84);
    return (0);
}