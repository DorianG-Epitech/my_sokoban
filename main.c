/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** main
*/

#include "my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int count = 0;

    while (str[count] != '\0') {
        my_putchar(str[count]);
        count++;
    }
    return (0);
}

void display_usage(void)
{
    my_putstr("USAGE\n");
    my_putstr("     ./my_sokoban map\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("     map  file representing the warehouse map,");
    my_putstr(" containing '#' for walls,\n");
    my_putstr("          'P' for the player, 'X' for boxes and");
    my_putstr("'O' for storage locations.\n");
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return (84);
    if (argv[1][0] == '-' && argv[1][1] == 'h') {
        display_usage();
        return (0);
    }
    if (arg_error(argv[1]) == 84)
        return (84);
    return (init_game(argv[1]));
}