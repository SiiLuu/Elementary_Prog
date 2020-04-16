/*
** EPITECH PROJECT, 2018
** matchstick
** File description:
** matchstick
*/

#ifndef _MATCHSTICK_H_
# define _MATCHSTICK_H_

typedef struct map_s
{
    char **tab;
    int lines;
    int stick;
    int match;
    int return_value;
} map_t;

void my_putchar(char);
int my_putstr(char *);
int my_atoi(char *);
void my_putnbr(int);
char **create_map(int, int);
void draw_map(map_t *);
int empty(map_t *);
int matches_gestion(map_t *, int);
void delete_matches(map_t *, int, int, int);
char *look_line(void);
void player(map_t *);

#endif