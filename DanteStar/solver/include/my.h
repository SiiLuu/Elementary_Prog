/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** dante
*/

#ifndef MY_H
#define MY_H

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

// In tools.c

int my_strlen(char *str);
int len_height(char *str);

// In str_to_word_tab.c
char **string_to_tab(char *buff, char **maze);
char **show_tab(char **tab);

// In solver_algo.c
int find_path(int x, int y, char **maze, char *buff);

#endif