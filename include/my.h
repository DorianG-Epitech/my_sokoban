/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** 
*/

#include <unistd.h>

int *move_right(int *pos);
int *move_left(int *pos);
int *move_down(int *pos);
int *move_up(int *pos);
int *move_player(int key, int *pos);
char *get_file(char const *filepath);
int *get_player_pos(char *str);
int check_win(char *str);
int no_move_possible(char str, int y, int x);
int is_player_blocked(char *str);
int init_game(char *str);
void put_goal(char *str);
int my_sokoban(char *map, char *str, int *pos);
void invalid_size(char *str);
int get_width(char *str);
int get_height(char *str);
int arg_error(char *str);
int char_error(char *str);