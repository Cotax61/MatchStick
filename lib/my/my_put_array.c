/*
** EPITECH PROJECT, 2019
** it put
** File description:
** a string on ur terminal.
*/

#include <unistd.h>

void my_putstr(char *str);

void my_put_array(char **arr, int new_line)
{
    int i = 0;

    while (arr[i] != 0) {
        my_putstr(arr[i]);
        write(1, "\n", 1);
        i++;
    }
    for (; new_line > 0; new_line--)
        write(1, "\n", 1);

}