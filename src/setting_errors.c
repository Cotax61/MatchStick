/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** Main function
*/

#include "my.h"

int is_get_error(int take)
{
    if (take <= 0) {
        my_put_error("Error: Take must be > 0\n");
        return (0);
    }
    return (1);
}

int is_line_error(int lines)
{
    if (lines < 1) {
        my_put_error("Error: Line must be > 1\n");
        return (0);
    }
    if (lines > 100) {
        my_put_error("Error: line number must be between 1 and 100\n");
        return (0);
    }
    return (1);
}