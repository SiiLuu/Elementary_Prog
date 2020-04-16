/*
** EPITECH PROJECT, 2018
** my_str_to_word_array
** File description:
** my_str_to_word_array
*/

#include "../../include/my.h"

char **my_str_to_word_array(char *str, char **tab, int nbr_line)
{
    unsigned int i = 0;
    unsigned int itab = 0;
    unsigned int jtab = 0;
    tab = NULL;

    tab = malloc(sizeof(char *) * nbr_line);
    for (jtab = 0; str[i] != '\0'; jtab++) {
        tab[jtab] = malloc(sizeof(char) * (malloc_str(str, i) + 2));
        while (str[i] != '\n')
            tab[jtab][itab++] = str[i++];
        i++;
        if (str[i] == '\0') {
            tab[jtab][itab] = '\n';
            tab[jtab][itab + 1] = '\0';
        }
        else
            tab[jtab][itab] = '\0';
        itab = 0;
    }
    tab[jtab] = NULL;
    return (tab);
}