/*
** EPITECH PROJECT, 2020
** lemin
** File description:
** found pos tunnel
*/

#include <stdlib.h>
#include "lemin.h"

static int check_tunnel(char *str)
{
    int nb = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '-') {
            nb++;
            break;
        }
    if (nb != 0)
        return (TRUE);
    else
        return (FALSE);
}

int found_pos_tunnel(values_t *v)
{
    if (v->ct == TRUE) {
        for (int i = 0; v->str[i] != NULL; i++) {
            if (v->str[i][0] == '#')
                continue;
            if (check_tunnel(v->str[i])) {
                v->pos_tunnel = i;
                break;
            }
        }
        return (SUCCESS);
    }
    else
        return (ERROR);
}
