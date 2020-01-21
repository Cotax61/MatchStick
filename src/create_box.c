/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** Main function
*/

#include <stdlib.h>

char **allocate_box(int size)
{
    char **box = malloc(sizeof(char *) * (size + 2));
    int i = 0;

    for (; i != size; i++)
        box[i] = malloc(sizeof(char) * size * 2 + 3);
    box[i] = NULL;
    return (box);
}

void draw_border(char *line, int size)
{
    for (int i = 0; i != size; i++)
        line[i] = '*';
    line[size] = '\0';
}

void draw_matches(char **box, int size)
{
    int col = 1;
    int line_size = size * 2 + 2;
    int matches = 1;

    for (int line = 1; line != size + 1; line++, col = 1, matches += 2) {
        box[line][0] = '*';
        for (; col != (line_size / 2) - line; col++)
            box[line][col] = ' ';
        for (int placed = 0; placed != matches; placed++, col++)
            box[line][col] = '|';
        for (; col != line_size - 2; col++)
            box[line][col] = ' ';
        box[line][col] = '*';
        box[line][col + 1] = '\0';
    }
}

char **create_box(int size)
{
    char **box = allocate_box(size + 2);
    int line = 1;

    draw_border(box[0], size * 2 + 1);
    draw_matches(box, size);
    draw_border(box[size + 1], size * 2 + 1);
    return (box);
}