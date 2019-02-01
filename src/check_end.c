/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** check_end
*/

#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "my.h"

int check_win(char *str)
{
    int count = 0;
    int x = 0;
    int y = 0;

    while (str[count] != '\0') {
        if (str[count] == 'O' &&
            (mvinch(y, x - 1) != 'X'))
            return (0);
        count++;
        x++;
        if (str[count] == '\n') {
            y++;
            x = 0;
        }
    }
    return (1);
}

int no_move_possible(char str, int y, int x)
{
    if (mvinch(y, x) != 'X' || str == 'O')
        return (0);
    if (mvinch(y - 1, x) == 'X' || mvinch(y - 1, x) == '#') {
        if (mvinch(y, x - 1) == 'X' || mvinch(y, x - 1) == '#')
            return (1);
    }
    if (mvinch(y, x - 1) == 'X' || mvinch(y, x - 1) == '#') {
        if (mvinch(y + 1, x) == 'X' || mvinch(y + 1, x) == '#')
            return (1);
    }
    if (mvinch(y + 1, x) == 'X' || mvinch(y + 1, x) == '#') {
        if (mvinch(y, x + 1) == 'X' || mvinch(y, x + 1) == '#')
            return (1);
    }
    if (mvinch(y, x + 1) == 'X' || mvinch(y, x + 1) == '#') {
        if (mvinch(y - 1, x) == 'X' || mvinch(y - 1, x) == '#')
            return (1);
    }
    return (0);
}

int is_player_blocked(char *str)
{
    int x = 0;
    int y = 0;
    int check = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == 'X')
            check++;
    }

    for (int count = 0; str[count] != '\0'; count++) {
        if (no_move_possible(str[count], y, x - 1) == 1)
            check--;
        x++;
        if (str[count] == '\n') {
            x = 0;
            y++;
        }
    }
    if (check == 0)
        return (1);
    return (0);
}