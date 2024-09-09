/*
** EPITECH PROJECT, 2020
** lemin
** File description:
** check tunnel negative
*/

#include <stdlib.h>
#include "lemin.h"

static int count_minus(char *str)
{
    int nb = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '-')
            nb++;
    return (nb);
}

void check_negative_tunnel(values_t *v)
{
    for (int i = v->pos_tunnel; v->str[i] != NULL; i++)
        if (count_minus(v->str[i]) != 1) {
            v->str[i] = NULL;
            v->err_lines = ERROR;
            break;
        }
}
