/*
** EPITECH PROJECT, 2020
** lemin
** File description:
** del commentaire
*/

#include <stdlib.h>
#include "lemin.h"

static int del_com_bis(values_t *v, int i, int j)
{
    if (multi_cmp(v->str[i]) == FALSE) {
        v->str[i] = NULL;
        for (j = i; j != v->lines - 1; j++)
            v->str[j] = v->str[j + 1];
        v->str[j] = NULL;
        i--;
    }
    return (i);
}

void del_com(values_t *v)
{
    int j = 0;

    for (int i = 0; v->str[i] != NULL; i++)
        if (v->str[i][0] == '#' && v->str[i][1] != '#')
            i = del_com_bis(v, i, j);
    for (int i = 0; v->str[i] != NULL; i++) {
        if (v->str[i][0] == '#' && v->str[i][1] != '#')
            i++;
        for (int k = 0; v->str[i][k] != '\0'; k++)
            if (v->str[i][k] == '#' && k != 0 && k != 1)
                v->str[i][k] = '\0';
    }

}
