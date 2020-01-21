/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** Main function
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "struct.h"
#include "matchstick.h"
#include "main.h"
#include "my.h"

game_t *setup_game(char **av)
{
    game_t *new = malloc(sizeof(game_t));
    int *matches;

    new->lines = my_getnbr(av[1]);
    new->max_take = my_getnbr(av[2]);
    if (!is_line_error(new->lines) || !is_get_error(new->max_take)) {
        free(new);
        return (NULL);
    }
    matches = malloc(sizeof(int) * new->lines);
    for (int i = 0; i != new->lines; i++)
        matches[i] = ((i + 1) * 2) - 1;
    new->matches = matches;
    return (new);
}

void display_end_msg(int msg)
{
    if (msg == 1)
        my_putstr("I lost... snif... but I'll get you next time!!\n");
    else if (msg == 2)
        my_putstr("You lost, too bad...\n");
}

int matchstick(int ac, char **av)
{
    game_t *game = NULL;
    char **box = NULL;
    int ret = 0;

    if (ac != 3)
        return (84);
    game = setup_game(av);
    if (game == NULL)
        return (84);
    box = create_box(game->lines);
    ret = game_loop(game, box);
    display_end_msg(ret);
    free(game->matches);
    my_free_array(box);
    free(game);
    return (ret);
}