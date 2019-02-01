/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** player_move
*/

#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "my.h"

int *move_up(int *pos)
{
    if (mvinch(pos[0] - 1, pos[1]) + mvinch(pos[0] - 2, pos[1]) < 123 ||
    mvinch(pos[0] - 1, pos[1]) + mvinch(pos[0] - 2, pos[1]) == 167) {
        if (mvinch(pos[0] - 1, pos[1]) == 'X' &&
            mvinch(pos[0] - 2, pos[1]) != '#')
            mvprintw(pos[0] - 2, pos[1], "X");
        mvprintw(pos[0], pos[1], " ");
        pos[0]--;
    }
    return (pos);
}

int *move_down(int *pos)
{
    if (mvinch(pos[0] + 1, pos[1]) + mvinch(pos[0] + 2, pos[1]) < 123 ||
    mvinch(pos[0] + 1, pos[1]) + mvinch(pos[0] + 2, pos[1]) == 167) {
        if (mvinch(pos[0] + 1, pos[1]) == 'X' &&
            mvinch(pos[0] + 2, pos[1]) != '#')
            mvprintw(pos[0] + 2, pos[1], "X");
        mvprintw(pos[0], pos[1], " ");
        pos[0]++;
    }
    return (pos);
}

int *move_left(int *pos)
{
    if (mvinch(pos[0], pos[1] - 1) + mvinch(pos[0], pos[1] - 2) < 123 ||
    mvinch(pos[0], pos[1] - 1) + mvinch(pos[0], pos[1] - 2) == 167) {
        if (mvinch(pos[0], pos[1] - 1) == 'X' &&
            mvinch(pos[0], pos[1] - 2) != '#')
            mvprintw(pos[0], pos[1] - 2, "X");
        mvprintw(pos[0], pos[1], " ");
        pos[1]--;
    }
    return (pos);
}

int *move_right(int *pos)
{
    if (mvinch(pos[0], pos[1] + 1) + mvinch(pos[0], pos[1] + 2) < 123 ||
    mvinch(pos[0], pos[1] + 1) + mvinch(pos[0], pos[1] + 2) == 167) {
        if (mvinch(pos[0], pos[1] + 1) == 'X' &&
            mvinch(pos[0], pos[1] + 2) != '#')
            mvprintw(pos[0], pos[1] + 2, "X");
        mvprintw(pos[0], pos[1], " ");
        pos[1]++;
    }
    return (pos);
}

int *move_player(int key, int *pos)
{
    if (key == KEY_UP && mvinch(pos[0] - 1, pos[1]) != '#')
        return (move_up(pos));
    if (key == KEY_DOWN && mvinch(pos[0] + 1, pos[1]) != '#')
        return (move_down(pos));
    if (key == KEY_LEFT && mvinch(pos[0], pos[1] - 1) != '#')
        return (move_left(pos));
    if (key == KEY_RIGHT && mvinch(pos[0], pos[1] + 1) != '#')
        return (move_right(pos));
    else
        return (pos);
}