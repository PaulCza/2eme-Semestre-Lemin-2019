/*
** EPITECH PROJECT, 2020
** lemin
** File description:
** atoi parsing
*/

#include <stdlib.h>
#include "lemin.h"

int cmp_value(int value, int *room, char **split)
{
    int i = 0;
    int j = 0;
    int nb = 0;

    for (; split[j] != NULL; j++);
    for (; i != j; i++) {
        if (value != room[i])
            nb++;
        else if (value == room[i])
            continue;
    }
    if (nb == j)
        return (TRUE);
    else
        return (FALSE);
}

int *atoi_parsing(char **str)
{
    int i = 0;
    int *tab;

    for (i = 0; str[i] != NULL; i++);
    tab = malloc(sizeof(int) * i);
    for (i = 0; str[i] != NULL; i++)
        tab[i] = my_atoi(str[i]);
    return (tab);
}
