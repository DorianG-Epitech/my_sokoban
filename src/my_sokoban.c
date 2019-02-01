/*
** EPITECH PROJECT, 2018
** my_sokoban.c
** File description:
** my_sokoban
*/

#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "my.h"

void put_goal(char *str)
{
    int count = 0;
    int x = 0;
    int y = 0;

    while (str[count] != '\0') {
        if (str[count] == 'O' && mvinch(y, x - 1) == ' ')
            mvprintw(y, x - 1, "O");
        count++;
        x++;
        if (str[count] == '\n') {
            y++;
            x = 0;
        }
    }
}

int my_sokoban(char *map, char *str, int *pos)
{
    for (int key; is_player_blocked(map) == 0; refresh()) {
        put_goal(map);
        key = getch();
        if (key == 32) {
            endwin();
            return (init_game(str));
        }
        pos = move_player(key, pos);
        mvprintw(pos[0], pos[1], "P");
        if (check_win(map) == 1) {
            endwin();
            return (0);
        }
    }
}