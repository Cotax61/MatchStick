/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** Main function
*/

#include <stdio.h>
#include <stdlib.h>
#include "player_turn.h"
#include "struct.h"
#include "my.h"

int player_line_error(game_t *setting, char **box, char *buff)
{
    int line = my_getnbr(buff);

    if (line > 0 && line <= setting->lines && setting->matches[line - 1] != 0)
        return (line);
    if (line < 0) {
        my_putstr("Error: invalid input (positive number expected)\n");
        return (0);
    }
    if (line == 0 || line > setting->lines)
        my_putstr("Error: this line is out of range\n");
    else if (setting->matches[line - 1] == 0)
        my_putstr("Error: this line is empty\n");
    return (0);
}

int player_matches_error(game_t *setting, char *buff, int line)
{
    int matches = my_getnbr(buff);

    if (matches == -1) {
        my_putstr("Error: invalid input (positive number expected\n");
        return (0);
    } else if (matches == 0) {
        my_putstr("Error: you have to remove at least one match\n");
        return (0);
    }
    if (setting->matches[line - 1] < matches) {
        my_putstr("Error: not enough matches on this line\n");
        return (0);
    } else if (matches > setting->max_take) {
        my_putstr("Error: you can't take that much matches !\n");
        return (0);
    }
    return (matches);
}

int get_player_matches(game_t *setting, char **box, int line)
{
    int matches = 0;
    char *buff = NULL;
    int r_size = 0;
    size_t size = 0;

    my_putstr("Matches: ");
    r_size = getline(&buff, &size, stdin);
    if (r_size == -1) {
        free (buff);
        buff = NULL;
        return (-1);
    }
    matches = player_matches_error(setting, buff, line);
    free (buff);
    buff = NULL;
    return (matches);
}

int get_player_line(game_t *setting, char **box)
{
    int line = 0;
    char *buff = NULL;
    int r_size = 0;
    size_t size = 0;

    while (line <= 0) {
        my_putstr("Line: ");
        r_size = getline(&buff, &size, stdin);
        if (r_size == -1) {
            free (buff);
            buff = NULL;
            return (-1);
        }
        line = player_line_error(setting, box, buff);
        free (buff);
        buff = NULL;
    }
    return (line);
}

int player_turn(game_t *setting, char **box)
{
    int line = 0;
    int matches = 0;

    while (matches == 0) {
        line = get_player_line(setting, box);
        if (line == -1)
            return (-1);
        matches = get_player_matches(setting, box, line);
    }
    if (matches == -1)
        return (-1);
    if (matches != -1) {
        remove_matches_from_box(box, line, matches);
        setting->matches[line - 1] -= matches;
    }
    say_what_player_has_done(line, matches);
    return (matches);
}