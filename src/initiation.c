/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** initiation
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <ncurses.h>
#include "my.h"

char *get_file(char const *filepath)
{
    struct stat st;
    char *buffer;
    int fd;

    stat(filepath, &st);
    buffer = malloc(sizeof(char) * st.st_size + 1);
    fd = open(filepath, O_RDONLY);
    read(fd, buffer, st.st_size);
    buffer[st.st_size] = '\0';
    return (buffer);
}

int *get_player_pos(char *str)
{
    int count = 0;
    int *pos = malloc(sizeof(int) * 2);

    pos[0] = 0;
    pos[1] = 0;
    while (str[count] != 'P') {
        count++;
        pos[1]++;
        if (str[count] == '\n') {
            pos[1] = 0;
            pos[0]++;
        }
    }
    pos[1]--;
    return (pos);
}

int init_game(char *str)
{
    char *map = get_file(str);
    int *pos = get_player_pos(map);

    if (char_error(map) == 84)
        return (84);
    initscr();
    curs_set(0);
    keypad(stdscr, true);
    mvprintw(0, 0, map);
    if (my_sokoban(map, str, pos) == 0)
        return (0);
    endwin();
    return (1);
}
