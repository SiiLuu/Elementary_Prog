/*
** EPITECH PROJECT, 2018
** my_pushswap
** File description:
** tools.
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *s)
{
    for (int i = 0 ; s[i] != 0 ; i++)
        my_putchar(s[i]);
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

int chars_errors(char *str)
{
    while (*str != '\0') {
        if ((*str < '0' || *str > '9') && *str != '-')
            return (1);
        str++;
    }
    return (0);
}

int my_atoi(char *str)
{
    int res = 0;
    int sign = 0;
    int i = 0;

    ((str[i] == '-') ? (sign = 1, i++) : (0));
    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            res *= 10;
            res += str[i] - '0';
        }
        else
            return (res);
        i++;
    }
    if (sign == 0)
        return (res);
    else
        return (-res);
}