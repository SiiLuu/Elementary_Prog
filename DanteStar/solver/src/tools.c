/*
** EPITECH PROJECT, 2018
** dante
** File description:
** solver / main
*/

#include "my.h"

int my_strlen(char *str)
{
    int a = 0;

    while (str[a] != '\n'){
        a++;
    }
    return (a);
}

int len_height(char *str)
{
    int i = 0;
    int j = 0;

    while (str[i] != '\0') {
        if (str[i] == '\n')
            j++;
        i++;
    }
    j++;
    return (j);
}