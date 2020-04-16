/*
** EPITECH PROJECT, 2018
** use_fonc
** File description:
** tools.
*/

#include <unistd.h>
#include <stdlib.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int a;
    a = 0;
    while (str[a] != '\0') {
        my_putchar(str[a]);
        a++;
    }
    return 0;
}

void    my_putnbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    if (nb >= 10) {
        my_putnbr(nb / 10);
        my_putnbr(nb % 10);
    }
    else
        my_putchar(nb + '0');
}

int len_width(char *str)
{
    int i = 0;
    int j = 0;

    while (str[i] != '\n')
        i++;
    i++;
    while (str[i] != '\n') {
        i++;
        j++;
    }
    return (j);
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
    return (j);
}