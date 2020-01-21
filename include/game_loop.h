/*
** EPITECH PROJECT, 2019
** my_print_alpha.c
** File description:
** print the alphabet in ascending order
*/

#ifndef GAME_LOOP_H
#define GAME_LOOP_H

#include "struct.h"

int player_turn(game_t *setting, char **box);
int ai_turn(game_t *status, char **box, int *matches);

#endif