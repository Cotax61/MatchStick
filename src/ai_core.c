/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** Main function
*/

#include "struct.h"
#include "my.h"

void remove_matches_from_box(char **box, int line, int matches);

void say_what_ia_done(int line)
{
    my_putstr("AI removed 1 match(es) from line ");
    my_put_nbr(line);
    my_putchar('\n');
}

int ai_turn(game_t *status, char **box, int *matches)
{
    int i = 0;

    for (; matches[i] == 0; i++);
    matches[i] -= 1;
    remove_matches_from_box(box, i + 1, 1);
    say_what_ia_done(i + 1);
    return (1);
}