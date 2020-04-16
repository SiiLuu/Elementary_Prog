/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** include for lemin
*/

#ifndef MY_H
#define MY_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct link {
    int ant;
    char *rname;
    struct link **links;
}link_t;

typedef struct file_error {
    int error_status;
    int room_nbr;
    int links_nbr;
    int line_error;
    int ants_error;
    int room_error;
    int room;
    int comment;
    int comment_link;
    char **room_name;
    char **link_name;
}file_error_t;

//In lib/my
void my_putchar(char c);
void my_putstr(char *str);
int my_putnbr(int nb);
int my_strlen(char const *str);
char *my_strcat(char *dest, char const *src);
int my_show_word_array(char **tab);
char **my_str_to_word_array(char *str, char **tab, int nbr_line);
int my_strcmp(char const *s1, char const *s2);
int my_printf(char *str, ...);
int my_putnbr_base_modified(int nbr, char const *base);
int my_putnbr_base(int nbr, char const *base);
int my_putstr_modified(char const *str);
unsigned int my_getnbr_base(char *str, char *base);
int my_strncmp(char *s1, char *s2, int n);

// In parsing.c
int malloc_str(char *str, int i);
int compt_number_line(const char *str);
char *get_input(char *str);
char **get_parameters(char **tab);

// In basi_map_parsing.c
void basic_map_parsing(char **tab);

//In wrong_anthill.c
int anthill_gestion(file_error_t *file_error, char **tab);

//In link_rooms.c
void link_rooms(file_error_t *ferror, link_t **link);

//In coord_room.c
void print_before_error(file_error_t *file_error, char **array);
int coord_error(file_error_t *file_error);
int check_number(file_error_t *file_error, int k, int i);

//In wrong_anthill_2.c
int command_or_comment(char **array, int k, int i);
int compare_link_betwen_room(char **array);
void print_room(file_error_t *file_error);
int check_link_nbr(char **array);
int flen(char *str);

//In input_in_array.c
int my_room_in_array(file_error_t *file_error, char **array);
void my_link_in_array(file_error_t *file_error, char **array);

// In ants.c
int ants(int i, char **tab);

#endif