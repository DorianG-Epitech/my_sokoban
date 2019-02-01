/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** arg_error
*/

#include "my.h"
#include <fcntl.h>

int arg_error(char *str)
{
    int fd;

    fd = open(str, O_RDONLY);
    if (fd == -1)
        return (84);
    return (0);
}