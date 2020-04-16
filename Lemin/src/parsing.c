/*
** EPITECH PROJECT, 2018
** lemin
** File description:
** parsing
*/

#include "my.h"

int compt_number_line(const char *str)
{
    unsigned int i = 0;
    unsigned int compt = 0;

    while (str[i] != '\0') {
        if (str[i] == '\n')
            compt++;
        i++;
    }
    return (compt);
}

char *get_input(char *str)
{
    char * line = NULL;
    size_t len = 0;
    ssize_t read = 0;
    int i = 0;

    while (1) {
        read = getline(&line, &len, stdin);
        if (read == -1) {
            i = my_strlen(str);
            while (str[i] == '\n' || str[i] == '\0')
                i--;
            str[i + 1] = '\n';
            str[i + 2] = '\0';
            return (str);
        }
        str = my_strcat(str, line);
    }
    return (str);
}

int malloc_str(char *str, int i)
{
    int compt = 0;

    while (str[i] != '\n') {
        compt++;
        i++;
    }
    return (compt);
}

char **remove_comment(char **tab)
{
    int i = 0;
    int j = 0;

    while (tab[j] != NULL) {
        if (tab[j][i] == '#' && tab[j][i + 1] != '#' &&
            !my_strcmp(tab[i], "##start") && !my_strcmp(tab[i], "##end")) {
                tab[j][i - 1] = '\0';
        }
        if (tab[j][i] == '\n' || tab[j][i] == '\0') {
            j++;
            i = 0;
        }
        i++;
    }
    return (tab);
}

char **get_parameters(char **tab)
{
    char *str = malloc(sizeof(char) * 10000);
    int nbr_line = 0;

    str = get_input(str);
    nbr_line = compt_number_line(str);
    tab = my_str_to_word_array(str, tab, nbr_line + 1);
    tab = remove_comment(tab);
    free(str);
    return (tab);
}
