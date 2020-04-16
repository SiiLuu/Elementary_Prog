/*
** EPITECH PROJECT, 2018
** my_bsq
** File description:
** bsq
*/

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#ifndef BSQ_H
#define BSQ_H

void my_putchar(char c);
void my_putnbr(int nb);
int my_putstr( char const *str);
int my_strlen(char *str);
int open_file(char *path);
int len_height(char *str);
int len_width(char *str);

#endif