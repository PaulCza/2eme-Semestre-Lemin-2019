/*
** EPITECH PROJECT, 2020
** lemin
** File description:
** check tunnel
*/

#include <stdlib.h>
#include "lemin.h"

void check_tunnels(values_t *v)
{
    int nbr = 0;

    for (int i = 1; v->str[i] != NULL; i++)
        for (int j = 0; v->str[i][j] != '\0'; j++)
            if (v->str[i][j] == '-')
                nbr++;
    if (nbr == 0) {
        v->err_lines = ERROR;
        v->ct = FALSE;
    }
    else
        v->ct = TRUE;
}
