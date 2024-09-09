/*
** EPITECH PROJECT, 2020
** lemin
** File description:
** check nbr
*/

#include "lemin.h"

int check_nbr(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9')
            continue;
        else
            return (TRUE);
    }
    return (FALSE);
}
