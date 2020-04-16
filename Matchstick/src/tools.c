/*
** EPITECH PROJECT, 2018
** use_fonc
** File description:
** tools.
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

static char *init(char *str, char c)
{
    int i = 0;
    int j = 0;
    char *string = NULL;

    while (str != NULL && str[i] != '\0')
        i++;
    string = malloc(sizeof(char) * (i + 2));
    while (j < i) {
        string[j] = str[j];
        j++;
    }
    string[j] = c;
    string[j + 1] = '\0';
    if (str != NULL)
        free(str);
    return (string);
}

char *look_line(void)
{
    int a = 0;
    char *str = NULL;
    char buffer[1];

    while ((a = read(0, buffer, 1))) {
        if (a == -1) {
            if (str != NULL)
                free(str);
            return (NULL);
        }
        if (buffer[0] == '\n')
            return (str);
        if (buffer[0] == EOF || !(str = init(str, buffer[0])))
            break;
    }
    if (str != NULL)
        free(str);
    return (NULL);
}