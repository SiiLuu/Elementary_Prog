/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** dante
*/

#ifndef MY_H
#define MY_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

// In error.c
int error_handling(int argc, char **argv);

// In generator.c
int main_generator(int argc, char **argv);

// In basic_map.c
char **basic_maze(char **tab);
void free_tab(char **tab,  char **argv);
void display_array(char **maze, int y);

// In create_wall.c
char **generate_lab(char **maze, char **argv);
char **generate_lab_imperfect(char **maze, char **argv);
char **small_maze(char **maze, char **argv);

#endif