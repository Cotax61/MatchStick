/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** say_action
*/

#include "my.h"

void say_what_player_has_done(int line, int matches)
{
    my_putstr("Player removed ");
    my_put_nbr(matches);
    my_putstr(" match(es) from line ");
    my_put_nbr(line);
    my_putchar('\n');
}