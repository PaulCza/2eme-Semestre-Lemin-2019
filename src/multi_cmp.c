/*
** EPITECH PROJECT, 2020
** lemin
** File description:
** multi_cmp
*/

#include "lemin.h"

int multi_cmp(char *str)
{
    if (my_strcmp(str, "##start"))
        return (TRUE);
    if (my_strcmp(str, "##end"))
        return (TRUE);
    return (FALSE);
}
