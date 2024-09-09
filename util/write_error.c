/*
** EPITECH PROJECT, 2020
** navy
** File description:
** write on the error output
*/

#include <unistd.h>
#include "lemin.h"

int write_error(char const *str)
{
    write(2, str, my_strlen(str));
    return (ERROR);
}
