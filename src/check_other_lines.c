/*
** EPITECH PROJECT, 2020
** lemin
** File description:
** check other lines
*/

#include <stdlib.h>
#include "lemin.h"

void check_other_lines(values_t *v)
{
    for (int i = 1; v->str[i] != NULL; i++) {
        if (v->str[i][0] == '#')
            continue;
        for (int j = 0; v->str[i][j]; j++) {
            if (v->str[i][j] >= '0' && v->str[i][j] <= '9')
                continue;
            else if (v->str[i][j] == '-' || v->str[i][j] == ' ')
                continue;
            else {
                v->str[i] = NULL;
                v->err_lines = ERROR;
            }
        }
    }
}
