/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** Main function
*/

#include "struct.h"
#include "game_loop.h"
#include "my.h"

int more_loop(game_t *status, char **box, int *total_matches)
{
    my_putstr("AI's turn...\n");
    *total_matches -= ai_turn(status, box, status->matches);
    my_put_array(box, (*total_matches == 0) ? 0 : 1);
    if (*total_matches == 0)
        return (1);
    return (0);
}

int game_loop(game_t *status, char **box)
{
    int total_matches = 0;
    int player_entry = 0;

    my_put_array(box, 1);
    for (int i = 0; i != status->lines; i++)
        total_matches += status->matches[i];
    while (total_matches != 0) {
        my_putstr("Your turn:\n");
        player_entry = player_turn(status, box);
        if (player_entry == -1)
            return (-1);
        total_matches -= player_entry;
        my_put_array(box, (total_matches == 0) ? 0 : 1);
        if (total_matches == 0)
            return (2);
        if (more_loop(status, box, &total_matches))
            return (1);
    }
}