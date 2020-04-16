/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** printf
*/

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUFF_SIZE 50000

#ifndef BSQ_H
#define BSQ_H

void my_putchar(char c);
void my_putnbr(int nb);
void my_putnbr_un(unsigned int nb);
int my_putstr( char const *str);
int my_strlen(char *str);
int my_putnbr_base(int nb, char *base);
int my_atoi(char *str);
int open_file(char *path);
int len_height(char *str);
int len_width(char *str);

#endif