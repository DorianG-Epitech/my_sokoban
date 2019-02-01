/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** char_error
*/

#include <stdio.h>

int check_char(char c)
{
    char *str = " #XOP\n";
    int count = 0;

    while (count <= 5) {
        if (c == str[count])
            return (1);
        count++;
    }
    return (0);
}

int char_error(char *str)
{
    int count = 0;

    while (str[count] != '\0') {
        if (check_char(str[count]) == 0)
            return (84);
        count++;
    }
    return (0);
}