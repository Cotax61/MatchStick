/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** Main function
*/

void remove_matches_from_box(char **box, int line, int matches)
{
    int i = 0;

    for (; box[line][i] != '|'; i++);
    for (; box[line][i] != ' ' && box[line][i] != '*'; i++);
    i--;
    for (int remov = 0; remov != matches; remov++, i--)
        box[line][i] = ' ';
}