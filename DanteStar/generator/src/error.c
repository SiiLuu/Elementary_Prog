/*
** EPITECH PROJECT, 2018
** dante
** File description:
** generator / main
*/

#include "my.h"

int check_char(char **argv)
{
    int i = 0;

    for (int j = 1; j != 3; j++) {
        while (argv[j][i] != '\0') {
            if (argv[j][i] > '9' || argv[j][i] < '0')
                return (1);
            i++;
        }
        i = 0;
    }
    return (0);
}

int error_handling(int argc, char **argv)
{
    if ((argc > 4 || argc < 3) || (atoi(argv[1]) <= 0 || atoi(argv[2]) <= 0))
        return (1);
    if (argc == 4  && strcmp(argv[3], "perfect") != 0)
        return (1);
    if (check_char(argv))
        return (1);
    return (0);
}