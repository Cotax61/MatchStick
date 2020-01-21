/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** my_free_array
*/

#include <stdlib.h>

void my_free_array(char **array)
{
    for (int i = 0; array[i]; i++)
        free(array[i]);
    free(array);
}